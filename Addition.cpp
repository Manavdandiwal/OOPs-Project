#include "Addition.h"


void Addition::initialize()
{
	for (int i = 0; i < N; i++)
	{
		nums[i] = random(level);
		correct_ans += nums[i];
	}
}

int Addition::repeat()
{
	while (!problem())
	{
		wrong_comments();
		score--;
		print_scores();
		cout << "Press any key to try again...";
		_getch();
		problem();
	}

	corr_comments();
	score += 3;
	print_scores();

	cout << "Are you ready for a new challenge! (1 / 0) : ";
	int choice;
	cin >> choice;
	return choice;
}

bool Addition::problem()
{
	system("cls");
	print_scores();
	cout << "Enter the value of following expression : " << endl;

	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
			cout << nums[i];
		else
			cout << nums[i] << " + ";
	}
	cout << endl;
	cout << "Answer : ";

	int user_value;
	cin >> user_value;

	if (user_value == correct_ans)
		return true;

	return false;
}