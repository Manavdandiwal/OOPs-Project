#include "Addition.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int random_number_generator(int length)
{
	static int inc = 0;
	int num = 0;
	srand(time(NULL) + inc);
	inc += 1;
	for (int i = 0; i < length; i++)
	{
		num = num * 10 + rand() % 10;
	}

	return num;
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#endif // !FUNCTIONS_H

void Addition::initialize()
{
	for (int i = 0; i < N; i++)
	{
		nums[i] = random_number_generator(level);
		correct_ans += nums[i];
	}
}

bool Addition::problem()
{
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
