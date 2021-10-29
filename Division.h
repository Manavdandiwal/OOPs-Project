#pragma once
#include "base_class.h"
class Division : protected base_class
{
    int correct_quot, correct_remain, divisor, dividend;
public:
    Division()
    {
        level = 1;
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
    bool problem(int sec);
};