#pragma once
#include "Addition.h"

extern void gotoxy(int x, int y);

void print_time(tm init, COORD pos)
{
	while (1)
	{
		gotoxy(100, 1);
		time_t current = time(0);
		tm curr;
		localtime_s(&curr, &current);
		cout << curr.tm_min - init.tm_min << " : " << curr.tm_sec - init.tm_sec; 

		if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
			break;
	}
	gotoxy(pos.X, pos.Y);
}

int main_menu(tm init)
{
	system("cls");
	gotoxy(0, 1);

	cout << " Choose an option from below : " << endl;
	cout << " 1 : Practice" << endl;
	cout << " 2 : Time Bound Practice" << endl;
	cout << " 3 : Quiz" << endl;
	cout << " 4 : Exit" << endl;
	cout << " Choice : ";
	int choice;
	cin >> choice;
	return choice;
}

int ques_type(tm init)
{
	//system("cls");
	//gotoxy(0, 1);
	cout << "Choose Mathematical Operation : " << endl;
	cout << "1 : Addition" << endl;
	cout << "2 : Subtraction" << endl;
	cout << "3 : Multiplication" << endl;
	cout << "4 : Division" << endl;
	cout << "5 : MIX" << endl;
	cout << "Choice : ";

	int choice;
	cin >> choice;

	return choice;
}

void rules(int choice, tm init)
{
	system("cls");
	gotoxy(0, 1);
	switch (choice)
	{
	case 1:
		cout << "This Practice exercise will be 10 minutes long." << endl;
		cout << "Each Question will be worth 1 point." << endl;
		break;

	case 2:
		cout << "You will have 10 seconds for each question." << endl;
		cout << "Each correct answer will be rewarded with 5 points and penalty for a wrong answer is 1 point. The question that is not answered will not be rewarded any point nor will be considered for penalty." << endl;
		break;

	case 3:
		cout << "Each Participant will have 10 seconds to answer to question. If NOT able to answer, the question will be passed to the next player. Passed question is worth 2 point." << endl;
		cout << "Each question is worth 5 points(not passed)" << endl;
		break;

	case 4:
		exit(0);
	}
}

int choose_level()
{
	cout << "Choose the level : " << endl;
	cout << "1 : Beginner" << endl;
	cout << "2 : Intermediate" << endl;
	cout << "3 : Hard" << endl;
	cout << "4 : Insane" << endl;
	int level;
	cin >> level;
	return level;
}