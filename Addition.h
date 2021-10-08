#pragma once
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include <thread>
using namespace std;

class Addition
{
	int* nums;
	int level, N;
	int correct_ans;

public:
	Addition(int level) 
	{
		srand(time(0));
		N = level + (int)rand() % 2;
		nums = new int[N];
		this->level = level;
		this->correct_ans = 0;
		this->initialize();
	}

	~Addition()
	{
		free(nums);
	}

	void initialize();

	bool problem();
};