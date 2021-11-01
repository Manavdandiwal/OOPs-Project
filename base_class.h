#pragma once
#include <chrono>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

class base_class
{
protected:
	enum types { TIME_BOUND, UNLIMITED_TIME, QUIZ };
	enum operations { addition, subtraction, multiplication, division };
	int level;
	int type;
	int op;
	int score;
	int* nums;
	int N;
public:
	base_class() { }

	static void input(int& ans)
	{
		/// <summary>
		/// used in multithreading
		/// </summary>
		/// <param name="ans"></param>
		cin >> ans;
	}

	base_class(int level, int type, int operation)
	{
		cout << "Howdy little magician!" << endl;
		cout << "It's time for you to buckle up and get ready for some intense arithmetic action" << endl;
		this->level = level;
		this->type = type;
		this->op = operation;
		score = 0;
	}

	int random(int length);
	void print_main_menu();
	void instructions();
	void time_exit(int sec);
	void gotoxy(int x, int y);
	void corr_comments();
	void wrong_comments();
	void print_scores();
};