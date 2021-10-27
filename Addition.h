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
	int* nums;
	int N;
	int correct_ans;

public:
	Addition()
	{
		srand(time(0));
		N = level + rand() % 2;

		nums = new int[N];
		this->correct_ans = 0;
		this->initialize();
	}

	~Addition()
	{
		free(nums);
	}

	void initialize();
	int repeat();
	bool problem();
};