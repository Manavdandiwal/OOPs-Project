#include "Addition.h"
#include "type_quiz.h"
#include "base_class.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include "Division.h"
#include "Practice_mode.h"
#include "mix_operation.h"
#include "time_bound.h"
using namespace std;

int print_main_menu();
int Operation_select();
int level_select();
void transition(int time, string str, char end = '\n');
void transition(int time, vector<string> str);
void print_top(int type, vector<pair<string, int>> top_performers, int max_len);
void transition2(int time, string str, int line);

int main()
{

    string start = "Heya there buddy! Welcome to MATHEZ. We will help make mathematics easy for you.";
    transition(35, start);
    this_thread::sleep_for(chrono::seconds(1));
    int type, operation, level;
    while (1)
    {
        type = print_main_menu();
        if (type < 4)
        {
            operation = Operation_select();
            level = level_select();
        }
        switch (type)
        {
        case 1:
            switch (operation)
            {
            case 1:
            {
                type_quiz<Addition> start(level, type, operation);
                break;
            }
            case 2:
            {
                type_quiz<Subtraction> start(level, type, operation);
                break;
            }
            case 3:
            {
                type_quiz<Division> start(level, type, operation);
                break;
            }
            case 4:
            {
                type_quiz<Multiplication> start(level, type, operation);
                break;
            }
            case 5:
            {
                type_quiz<mix_operation> start(level, type, operation);
                break;
            }
            default:
                cout << "Invalid Choice" << endl;
                exit(1);
            }
            break;

        case 2:
            switch (operation)
            {
            case 1:
            {
                time_bound<Addition> start(60, level, type, operation);
                break;
            }
            case 2:
            {
                time_bound<Subtraction> start(60, level, type, operation);
                break;
            }
            case 3:
            {
                time_bound<Division>  start(60, level, type, operation);
                break;
            }
            case 4:
            {
                time_bound<Multiplication>  start(60, level, type, operation);
                break;
            }
            case 5:
            {
                time_bound<mix_operation>  start(60, level, type, operation);
                break;
            }
            default:
                cout << "Invalid Choice" << endl;
                exit(1);
            }
            break;

        case 3:
            switch (operation)
            {
            case 1:
            {
                Practice_mode<Addition> start(level, type, operation);
                break;
            }
            case 2:
            {
                Practice_mode<Subtraction> start(level, type, operation);
                break;
            }
            case 3:
            {
                Practice_mode<Division> start(level, type, operation);
                break;
            }
            case 4:
            {
                Practice_mode<Multiplication> start(level, type, operation);
                break;
            }
            case 5:
            {
                Practice_mode<mix_operation> start(level, type, operation);
                break;
            }
            default:
                cout << "Invalid Choice" << endl;
                exit(1);
            }
            break;

        case 4:
        {
            system("cls");
            fstream quiz("Quiz.txt");
            vector<pair<string, int>> top_quiz;
            string name;
            int points, max_prac = 0, max_bound = 0, max_quiz = 0;

            while (getline(quiz, name) && quiz >> points)
            {
                if (name.length() > max_quiz) 
                    max_quiz = name.length();
                top_quiz.push_back({ name, points });
                quiz.ignore();
            }

            fstream practice("Practice.txt");
            vector<pair<string, int>> top_prac;
            while (getline(practice, name) && practice >> points)
            {
                if (name.length() > max_prac) 
                    max_prac = name.length();
                top_prac.push_back({ name, points });
                practice.ignore();
            }

            fstream time_bound("Time_bound.txt");
            vector<pair<string, int>> top_time;

            while (getline(time_bound, name) && time_bound >> points)
            {
                if (name.length() > max_bound) 
                    max_bound = name.length();
                top_time.push_back({ name, points });
                time_bound.ignore();
            }
            
            print_top(1, top_quiz, max_quiz);
            print_top(2, top_prac, max_prac);
            print_top(3, top_time, max_bound);
            cout << "Press any key to go to main menu" << endl;
            _getch();
            break;
        }

        case 5:
        {
            base_class tmp;
            tmp.show_report();
            break;
        }
        case 6:
            system("cls");
            cout << "Thank you, hope you enjoyed the brainstorimg mathematical Questions.";
            exit(0);
            break;
        }
    }
}

int print_main_menu()
{
    system("cls");
    vector<string> options(7);
    options[0] = " Select mode of game";
    options[1] = " 1. Quiz Time";
    options[2] = " 2. Time bound practice";
    options[3] = " 3. Long Challenge";
    options[4] = " 4. Top Performers";
    options[5] = " 5. Check your performance.";
    options[6] = " 6. Bored?? -> Exit";

    transition(20, options);

    transition(15, " Choice :", ' ');
    int choice;
    cin >> choice;
    return choice;
}

int Operation_select()
{
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
    vector<string> options(6);
    options[0] = " Choose the Mathematical Operation you want to play with : ";
    options[1] = " 1. Addition";
    options[2] = " 2. Subtraction";
    options[3] = " 3. Division";
    options[4] = " 4. Multiplication";
    options[5] = " 5. All Mixed Up";
    transition(20, options);
    transition(15, " Choice :", ' ');
    int operation;
    cin >> operation;
    return operation;
}

int level_select()
{
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");

    vector<string> options(5);
    options[0] = " Select Level of game : ";
    options[1] = " 1. Easy";
    options[2] = " 2. Medium";
    options[3] = " 3. Hard";
    options[4] = " 4. Insane";

    transition(20, options);

    transition(15, " Level :", ' ');
    int level;
    cin >> level;
    return level;
}

void transition(int time, string str, char end)
{
    for (auto i : str)
    {
        cout << i;
        this_thread::sleep_for(chrono::milliseconds(time));
    }
    cout << end;
}

void transition2(int time, string str, int line)
{
    int i = 0, j = str.length();
    while (i < j)
    {
        gotoxy(i, line);
        cout << str[i];
        i++;
        j--;
        if (i > j)
            break;
        //this_thread::sleep_for(chrono::milliseconds(time));
        gotoxy(j, line);
        cout << str[j];
        //j--;
        //this_thread::sleep_for(chrono::milliseconds(time));
    }
}

void transition(int time, vector<string> str)
{
    for (int i = 0; i < str.size(); i++)
    {
        transition(time, str[i]);
    }
}

void input2(float& a)
{
    cin >> a;
}

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_top(int type, vector<pair<string, int>> top_performers, int max_len)
{
    vector<string> types = { "Quiz", "Practice", "Time Bound" };
    gotoxy(23, 9 * (type - 1) + 1);
    cout << types[type - 1] << endl;
    gotoxy(1, 9 * (type - 1) + 3);
    cout << "Rank" << setfill(' ') << setw(10) << "Name" << setfill(' ') << setw(20 + max_len) << "Scores" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i >= top_performers.size())
        {
            cout << " " << i + 1 << setfill(' ') << setw(9);
            cout << "" << setfill('-') << setw(4) << "" << setfill(' ') << setw(14 + max_len) << "";
            cout << "" << setfill('-') << setw(5) << "";
            cout << endl;
        }
        else
        {
            int dig = 0, temp = top_performers[i].second;//for using manipulator
            while (temp != 0) {
                temp /= 10;
                dig++;
            }

            cout << " " << i + 1 << setfill(' ')
                << setw(top_performers[i].first.length() + 9) << top_performers[i].first <<
                setfill(' ') << setw(14 + max_len + 4 - top_performers[i].first.length() + dig) <<
                top_performers[i].second << endl;
        }

    }
}