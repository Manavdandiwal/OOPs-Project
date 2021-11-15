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
void print_top(int type, vector<pair<string, int>> top_performers);

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
            int points;

            while (getline(quiz, name) && quiz >> points)
                top_quiz.push_back({ name, points });


            fstream practice("Practice.txt");
            vector<pair<string, int>> top_prac;
            while (getline(practice, name) && practice >> points)
                top_prac.push_back({ name, points });


            fstream time_bound("Time_bound.txt");
            vector<pair<string, int>> top_time;

            while (getline(time_bound, name) && time_bound >> points)
                top_time.push_back({ name, points });
            //break;

            print_top(1, top_quiz);
            print_top(2, top_prac);
            print_top(3, top_time);
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

void print_top(int type, vector<pair<string, int>> top_performers)
{
    vector<string> types = {"Quiz", "Practice", "Time Bound"};
    gotoxy(23, 9 * (type - 1) + 1);
    cout << types[type - 1] << endl;
    gotoxy(1, 9 * (type - 1) + 3);
    cout << "Rank" << setw(20) << "Name" << setw(20) << "Scores" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i >= top_performers.size())
        {
            cout << i + 1 << "-" << "-" << endl;
            continue;
        }
        else
            cout << i + 1 << top_performers[i].first << top_performers[i].second << endl;
    }
}