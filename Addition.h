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
	Addition()
	{
		level = 1;
		srand(time(0));
		N = level + 1 + rand() % (4 - level);
		nums = new int[N];
		this->correct_ans = 0;
		this->initialize();
	}

	~Addition()
	{
		free(nums);
	}

	void initialize();
	bool problem(int);
};