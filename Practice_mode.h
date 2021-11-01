#pragma once
#include "base_class.h"

template<class T>
class Practice_mode : protected base_class
{
	T* ques;
	int scores = 0;
public:
	Practice_mode();
	void problem();
};

template<class T>
Practice_mode<T>::Practice_mode()
{
	cout << "Each correct answer will be awarded 5 marks minus the number of wrong attempts. There will be no negative marking. So, after 5 wrong attempts for a given question, the question will be changed." << endl;
	problem();
}

template<class T>
void Practice_mode<T>::problem()
{
	ques = new T;
	int score = 5;
	while (!ques->problem() && score)
		score--;

	if (score)
	{
		scores += score;
		cout << "Do you want to continue? (1 / 0) : ";
		int choice;
		cin >> choice;

		if (choice)
			problem();
	}

	else
		problem();
}