#pragma once
#include "base_class.h"

template<class T>
class type_quiz : protected base_class
{
	T *ques;
	vector<pair<string, int>> participants;
	int max_len;
public:
	type_quiz();
	static bool compare(pair<string, int> a, pair<string, int> b)
	{
		return a.second > b.second;
	}
	void contest();
};


template<class T>
inline type_quiz<T>::type_quiz()
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
}


template<class T>
void type_quiz<T>::contest()
{
	int start = 0;
	int curr = 0;
	int marks;
	int ques_no = 0;

	for (start = 0; ques_no <= 1; start = (start + 1) % participants.size())
	{
		if (!start)
			ques_no++;

		if (ques_no > 1)
			break;
		marks = 3;
		ques = new T;
		system("cls");
		cout << participants[start].first << "'s turn : " << endl
			<< endl;
		if (ques->problem(7))
		{
			participants[start].second += marks;
			continue;
		}
		marks = 1;
		for (curr = (start + 1) % participants.size(); curr != start; curr = (curr + 1) % participants.size())
		{
			system("cls");
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
	cout << "RANK" << setw(8) << "NAME" << setw(max_len + 4) << "SCORE" << endl;
	cout << setw(17 + max_len) << setfill('-') << ' ' << endl;
	for (int i = 0; i < 3 && i < participants.size(); i++)
	{
		cout << setfill(' ') << i + 1 << setw(7 + participants[i].first.length()) << participants[i].first << setw(4 + max_len - participants[i].first.length()) << participants[i].second << endl;
	}
}