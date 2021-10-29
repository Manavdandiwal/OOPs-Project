#include "Subtraction.h"

void Subtraction::initialize()
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		nums[i] = random(level + rand() % 2);
		correct_ans -= nums[i];
	}
}

bool Subtraction::problem()
{
	system("cls");
	print_scores();
	cout << "Enter the value of following expression : " << endl;

	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
			cout << "( " << nums[i] << " )";
		else
			cout << "( " << nums[i] << " )" << " - ";
	}
	cout << endl;
	cout << "Answer : ";

	int user_value;
	cin >> user_value;

	if (user_value == correct_ans)
		return true;

	return false;
}