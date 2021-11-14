#pragma once
#include "base_class.h"
extern class base_class;
class Division : protected base_class
{
    int correct_quot, correct_remain, divisor, dividend;
public:
    Division(int level, int type, int operation) : base_class(level, type, op)
    {
        N = min(level, 2);
        this->initialize();
    }
    static void input(int& quot, int& rem)
    {
        cout << "Quotient : ";
        cin >> quot;
        cout << "Remainder : ";
        cin >> rem;
    }

    void initialize();
    bool problem(int sec = 0);
};