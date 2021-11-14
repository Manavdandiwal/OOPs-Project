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
#include <stack>
#include <fstream>
using namespace std;

extern void gotoxy(int x, int y);
extern void transition(int time, string str, char end);
extern void transition(int time, vector<string> str);

class base_class
{
protected:
	int level, type, op, score;
	int* nums;
	int N;
public:
	base_class() {};
	base_class(int level, int type, int operation);

	int random(int length);
	void time_exit(int sec);
	friend void gotoxy(int x, int y);
	friend void transition(int time, string str, char end);
	friend void transition(int time, vector<string> str);
	void corr_comments();
	void wrong_comments();
	void print_scores();
	void show_report();

	static void input(int& ans)
	{
		cin >> ans;
	}

	~base_class()
	{
		free(nums);
	}
};