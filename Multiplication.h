#pragma once
#include "base_class.h"
class Multiplication : protected base_class
{
	int correct_ans;

public:
	Multiplication()
	{
		level = 1;
		N = level + 1 + rand() % 2;
		nums = new int[N];
		initialize();
	}
	void initialize();
	bool problem(int);
};