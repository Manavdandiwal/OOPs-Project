#include "Addition.h"
#include "type_quiz.h"
#include "base_class.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include "Division.h"
#include "Practice_mode.h"
#include "time_bound.h"

base_class::base_class(int level, int type, int operation)
{
    this->level = level;
    this->type = type;
    this->op = operation;
    score = 0;
}

int base_class::random(int length)
{
    static int inc;
    int temp;
    srand(time(NULL) + inc);
    int num = 0;
    temp = rand() % 10;
    while (!temp)
    {
        temp = rand() % 10;
    }
    num = temp;
    while (--length)
    {
        num = num * 10 + rand() % 10;
    }
    num = num * pow(-1, rand() % 2);
    inc++;
    return num;
}

void base_class::time_exit(int sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void base_class::corr_comments()
{
    vector<string> comments(5);
    comments[0] = "Wonderful! You made it to the next level!";
    comments[1] = "Great job! You came up with a thoughtful answer and really nailed that question!";
    comments[2] = "Congratulations! You proactively solved this problem and achieved success.";
    comments[3] = "How Extraordinary! Be proud of yourself.";
    comments[4] = "Wow! This is a huge step for you in math! Incredible!";

    cout << comments[abs(rand()) % 5] << endl;
}

void base_class::wrong_comments()
{
    vector<string> comments(5);
    comments[0] = "Wrong Answer! But never say 'die'.Reach for the stars!";
    comments[1] = "Cant help, Hang in there! Try harder next time !!";
    comments[2] = "Sorry ! Better Luck next time. Don't let a first-time failure stop further attempts.";
    comments[3] = "Don't give up. Keep pushing harder!";
    comments[4] = "Apologies! Come on , You can do it ! Keep fighting !!!";

    cout << comments[abs(rand()) % 5] << endl;
}

void base_class::print_scores()
{
    gotoxy(100, 0);
    cout << "Scores : " << score;
    gotoxy(0, 0);
}

/// <summary>
/// formatting to be done here by @JASKEERAT
/// </summary>
void base_class::show_report()
{
    cin.ignore();
    string name;
    cout << "Enter the name : ";
    getline(cin, name);
    for (auto& i : name)
        if (i == ' ')
            i = '_';

    string file_name = "Quiz_" + name + ".txt";
    vector<int> points;
    ifstream file1(file_name);
    int point = 0;

    while (file1 >> point)
        points.push_back(point);

    // print quiz report
    system("cls");
    gotoxy(50, 1);
    cout << "Quiz Report" << endl;
    gotoxy(0, 3);

    cout << "Quiz number" << "Marks" << "Progress";
    for (int i = 0; i < points.size(); i++)
    {
        cout << i + 1 << points[i];
        if (!i)
            cout << points[i] << endl;

        else
            cout << points[i] - points[i - 1] << endl;
    }

    cout << "Press any key to view Practice Report...";
    _getch();

    file_name = "Practice_" + name + ".txt";
    ifstream file2(file_name);
    points.clear();
    while (file2 >> point)
        points.push_back(point);

    system("cls");
    gotoxy(50, 1);
    cout << "Practice Report" << endl;
    gotoxy(0, 3);

    cout << "Quiz number" << "Marks" << "Progress";
    for (int i = 0; i < points.size(); i++)
    {
        cout << i + 1 << points[i];
        if (!i)
            cout << points[i] << endl;

        else
            cout << points[i] - points[i - 1] << endl;
    }

    cout << "Press any key to view Practice Report...";
    _getch();

    file_name = "Time_" + name + ".txt";
    ifstream file3(file_name);
    points.clear();
    while (file3 >> point)
        points.push_back(point);

    system("cls");
    gotoxy(50, 1);
    cout << "Time bound practice Report" << endl;
    gotoxy(0, 3);

    cout << "Quiz number" << "Marks" << "Progress";
    for (int i = 0; i < points.size(); i++)
    {
        cout << i + 1 << points[i];
        if (!i)
            cout << points[i] << endl;

        else
            cout << points[i] - points[i - 1] << endl;
    }

    cout << "Press any key to return to main menu...";
    _getch();
}