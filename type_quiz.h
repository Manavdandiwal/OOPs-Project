#pragma once
#include "base_class.h"

template<class T>
class type_quiz : protected base_class
{
	T *ques;
	vector<pair<string, int>> participants;
	int max_len;
public:
	type_quiz(int level, int type, int operation);
	static bool compare(pair<string, int> a, pair<string, int> b)
	{
		return a.second > b.second;
	}
	void contest();
};


template<class T>
inline type_quiz<T>::type_quiz(int level, int type, int operation) : base_class(level, type, operation)
{
	max_len = 0;
	int number;
	cout << "Number of Participants : ";
	cin >> number;
	string name;
	cin.ignore();
	for (int i = 0; i < number; i++)
	{
		cout << i + 1 << "th player name : ";
		getline(cin, name);
		max_len = max(name.length(), max_len);
		participants.push_back(make_pair(name, 0));
	}
	cout << "Let the QUIZ begin." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	contest();
}


template<class T>
void type_quiz<T>::contest()
{
	ofstream top_performers("Quiz.txt");
	int start = 0;
	int curr = 0;
	int marks;
	int ques_no = 0;

	for (start = 0; ques_no <= 5; start = (start + 1) % participants.size())
	{
		if (!start)
			ques_no++;

		if (ques_no > 5)
			break;
		cout << ques_no << " : ";
		marks = 3;
		ques = new T(level, type, op);
		system("cls");
		gotoxy(105, 0);
		cout << "Scores : " << participants[start].second << flush;
		gotoxy(3, 1);
		cout << participants[start].first << "'s turn : " << endl
			<< endl;
		if (ques->problem(7))
		{
			participants[start].second += marks;
			continue;
		}

		else
			participants[start].second -= 1;

		marks = 1;
		for (curr = (start + 1) % participants.size(); curr != start; curr = (curr + 1) % participants.size())
		{
			system("cls");
			gotoxy(105, 0);
			cout << "Scores : " << participants[curr].second << flush;
			gotoxy(3, 1);
			cout << participants[curr].first << "'s turn : " << endl;
			cout << "This is a passed ques worth 1 point" << endl
				<< endl;
			if (ques->problem(5))
			{
				participants[curr].second += marks;
				break;
			}
		}
	}
	system("cls");
	cout << "CONTEST OVER" << endl;
	sort(participants.begin(), participants.end(), compare);

	cout << endl;
	cout << "Top participants of the contest are : " << endl
		<< endl;
	cout << "RANK" << setw(8) << "NAME" << setw(max_len + 8) << "SCORE" << endl;
	cout << setw(21 + max_len) << setfill('-') << ' ' << endl;
	for (int i = 0; i < 3 && i < participants.size(); i++)
	{
		cout << setfill(' ') << i + 1 << setw(7 + participants[i].first.length()) << participants[i].first << setw(8 + max_len - participants[i].first.length()) << participants[i].second << endl;
	}

	for (int i = 0; i < participants.size(); i++)
	{
		top_performers << participants[i].first << endl;
		top_performers << participants[i].second << endl;
	}
	top_performers.close();

	string file_name;

	for (auto participant : participants)
	{
		for (auto& i : participant.first)
			if (i == ' ')
				i = '_';

		file_name = "Quiz_";
		file_name += participant.first;
		file_name += ".txt";

		ofstream file(file_name, ios_base::app);
		file << participant.second << endl;
		file.close();
	}
	cout << "Press any key to continue...";
	_getch();
}