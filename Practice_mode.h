#pragma once
#include "base_class.h"

template<class T>
class Practice_mode : protected base_class
{
	string name;
	T* ques;
	int scores = 0;
	int positive_marked = 0, wrong = 0;
	int ques_number = 0;
	vector<pair<string, int>> top_performers;
public:
	Practice_mode(int level, int type, int operation);
	void problem();
	~Practice_mode();
};

template<class T>
Practice_mode<T>::Practice_mode(int level, int type, int operation) : base_class(level, type, operation)
{
	fstream file("Practice.txt");
	string name;
	int points;
	while (getline(file, name) && file >> points)
	{
		top_performers.push_back({ name, points });
	}
	file.close();
	cout << "Enter Your Name : ";
	cin.ignore();
	getline(cin, name);
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Each correct answer will be awarded 5 marks minus the number of wrong attempts. There will be no negative marking. So, after 5 wrong attempts for a given question, the question will be changed." << endl;
	this_thread::sleep_for(chrono::seconds(5));
	problem();
}

template<class T>
void Practice_mode<T>::problem()
{
new_problem:
	ques_number++;
	system("cls");
	gotoxy(105, 0);
	cout << "Scores : " << scores << endl;
	gotoxy(0, 0);
	ques = new T(level, type, op);
	int score = 5;
	while (!ques->problem() && score)
	{
		wrong++;
		system("cls");
		gotoxy(105, 0);
		cout << "Scores : " << scores << endl;
		gotoxy(0, 0);
		score--;
	}
	if (score)
		positive_marked++;

	if (ques_number == 10)
	{
		int percentage = positive_marked * 10;
		if (percentage >= 70)
		{
			level++;
			level = min(4, level);
		}
	}

	if (score)
	{
		scores += score;
		cout << "Do you want to continue? (1 / 0) : ";
		int choice;
		cin >> choice;

		if (choice)
			goto new_problem;

		else
		{
			system("cls");
			cout << "Your Total Score is : " << scores << endl;
			this_thread::sleep_for(chrono::seconds(3));
		}
	}

	else
		goto new_problem;

	if (top_performers.size() < 3)
		top_performers.push_back({ name, scores });

	else
	{
		int j = 2;
		while (top_performers[j].second < scores && j > 0)
		{
			j--;
			top_performers[j + 1] = top_performers[j];
		}
		top_performers[j] = { name, scores };
	}

	ofstream file("Practice.txt");

	for (int i = 0; i < top_performers.size(); i++)
	{
		file << top_performers[i].first << endl
			<< top_performers[i].second << endl;
	}
	file.close();
}

template<class T>
inline Practice_mode<T>::~Practice_mode()
{
	for (auto& i : name)
		if (i == ' ')
			i = '_';

	string file_name = "Practice_" + name + ".txt";
	ofstream file(file_name, ios_base::app);
	file << scores << endl;
	file.close();
}
