#pragma once
#include "base_class.h"
#include <ctime>

template<class T>
class time_bound : protected base_class
{
	int Time;
	T* ques;
	int scores;
	string name;
	vector<pair<string, int>> top_performers;
public:
	time_bound(int Time, int level, int type, int operation);
	void problem();
	~time_bound();
};

template<class T>
time_bound<T>::time_bound(int Time, int level, int type, int operation) : base_class(level, type, operation)
{
	fstream file("Time_bound.txt");
	string Name;
	int points;
	while (getline(file, Name) && file >> points)
		top_performers.push_back({ Name, points });
	file.close();

	this->Time = Time + 30;
	scores = 0;
	cout << "Enter your Name : ";
	cin.ignore();
	getline(cin, name);
	problem();
}

template<class T>
void time_bound<T>::problem()
{
	system("cls");
	time_t init = time(0);
	while (1)
	{
		system("cls");
		ques = new T(level, type, op);
		time_t end = time(0);
		if (end - init >= Time)
			break;
		gotoxy(105, 0);
		cout << "Scores : " << scores;
		gotoxy(0, 0);
		while (!ques->problem() && end - init < Time)
			end = time(0);

		if (end - init < Time)
			scores += 3;
	}

	system("cls");
	cout << "Your Total Score is : " << scores << endl;
	this_thread::sleep_for(chrono::seconds(3));

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
inline time_bound<T>::~time_bound()
{
	for (auto& i : name)
		if (i == ' ')
			i = '_';

	string file_name = "Time_" + name + ".txt";
	ofstream file(file_name, ios_base::app);
	file << scores << endl;
	file.close();
}