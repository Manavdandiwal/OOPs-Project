#pragma once
#include "base_class.h"
class Subtraction : protected base_class
{
	int correct_ans;
public:
	void initialize();
	Subtraction()
	{
		level = 1;
		srand(time(0));
		N = level + 1 + rand() % (4 - level);
		nums = new int[N];
		this->correct_ans = 0;
		this->initialize();
	}

	~Subtraction()
	{
		free(nums);
	}
	bool problem(int);
};