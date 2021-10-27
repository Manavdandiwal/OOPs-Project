#include<iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y)
{

	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	gotoxy(100, 0);
	cout << "Scores : 0";
	gotoxy(0, 0);
	cout << "Hello World" << endl;
}