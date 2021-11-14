#pragma once
#include "base_class.h"
extern class base_class;

class Multiplication : protected base_class
{
	int correct_ans;

public:
	Multiplication(int level, int type, int operation) : base_class(level, type, op)
	{
		N = level + 1 + rand() % 2;
		nums = new int[N];
		initialize();
	}
	void initialize();
	bool problem(int sec = 0);
};