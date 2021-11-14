#pragma once
#include "base_class.h"

extern void input2(float& a);

class mix_operation : public base_class
{
	int correct_ans;
	string ques;
public:
	mix_operation(int level, int type, int operation) : base_class(level, type, op)
	{
		srand(time(0));
		N = level + 1 + rand() % (5 - level);
		nums = new int[N];
		this->correct_ans = 0;
		this->initialize();
		ques = "";
	}
	friend void input2(float& a);
	void initialize();
	bool problem(int a = 0);
    int precedence(char op);    
    float applyOp(int a, int b, char op);
	float evaluate(string tokens);
};