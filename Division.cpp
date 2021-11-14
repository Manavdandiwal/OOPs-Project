#include "Division.h"

void Division::initialize()
{
	divisor = random(N);
	if (divisor <= 0)
		divisor = -divisor + 1;
	dividend = random(N * (rand() % 2 + 2));
	if (dividend <= 0)
		dividend = -dividend + 1;
	correct_quot = dividend / divisor;
	correct_remain = dividend % divisor;
}

bool Division::problem(int sec)
{
	/// <summary>
	/// prints the problem and asks the user for ans.
	/// </summary>
	/// <param name="sec">time to solve the ques</param>
	/// <returns>if the ans is correct or not</returns>
	cout << "Enter the value of following expression : " << endl;

	cout << dividend << " / " << divisor << endl;
	cout << endl;
	int quot = -1, rem = -1;
	// creating a thread for input so that we can exit this function after some time if user does not answer the ques.
	thread ANS(Division::input, std::ref(quot), ref(rem));
	time_exit(sec);
	/*ANS.detach();
	if (quot == correct_quot && rem == correct_remain)
		return true;

	return false;*/
	if (sec)
	{
		time_exit(sec);
		ANS.detach();
		system("cls");
	}

	if (!sec)
	{
		ANS.join();
		system("cls");
	}

	if (quot == correct_quot && rem == correct_remain)
	{
		cout << "Your answer is correct" << endl;
		corr_comments();
		this_thread::sleep_for(chrono::seconds(3));
		return true;
	}

	if (quot == -1 || rem == -1)
	{
		cout << "Time's UP!" << endl;
		cout << "You did not answered the question." << endl;
	}

	else
		cout << "Your answer is Wrong." << endl;

	wrong_comments();
	this_thread::sleep_for(chrono::seconds(3));
	return false;
}
