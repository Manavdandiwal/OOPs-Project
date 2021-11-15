#pragma once
#include "base_class.h"
#include <chrono>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <thread>
using namespace std;

class Addition : protected base_class
{
	int correct_ans;

public:
	Addition(int level, int type, int operation) : base_class(level, type, op)
	{
		srand(time(0));
		N = level + 1 + rand() % (5 - level);
		nums = new int[N];
		this->correct_ans = 0;
		this->initialize();
	}

	~Addition()
	{
		free(nums);
	}

	void initialize();
	bool problem(int a = 0);
};