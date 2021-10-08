#include <iostream>
#include "Main_functions.h"
using namespace std;

extern void gotoxy(int x, int y);
int main()
{
	tm init;
	time_t initial = time(0);
	localtime_s(&init, &initial);
	while (1)
	{
		Addition A(2);
		A.initialize();
		A.problem();
	}
}