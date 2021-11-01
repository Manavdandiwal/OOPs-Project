#include "Subtraction.h"

void Subtraction::initialize()
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		nums[i] = random(level + rand() % 2);
		if (!i)
			correct_ans = nums[i];

		else
			correct_ans += -1 * nums[i];
	}
}

bool Subtraction::problem(int sec)
{
	/// <summary>
	/// prints the problem and asks the user for ans.
	/// </summary>
	/// <param name="sec">time to solve the ques</param>
	/// <returns>if the ans is correct or not</returns>
	cout << "Enter the value of following expression : " << endl;

	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
			cout << "( " << nums[i] << " )";
		else
			cout << "( " << nums[i] << " )" << " - ";
	}
	cout << endl;
	cout << "correct ans : " << correct_ans << endl;
	cout << "Answer : ";

	int user_value = INT_MIN;
	// creating a thread for input so that we can exit this function after some time if user does not answer the ques.
	thread ANS(input, std::ref(user_value));
	time_exit(sec);
	ANS.detach();
	if (user_value == correct_ans)
		return true;

	return false;
}