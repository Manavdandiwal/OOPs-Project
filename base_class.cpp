#include "base_class.h"
#include "Addition.h"

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

    inc++;
    return num;
}

void base_class::print_main_menu()
{
    cout << "Howdy little magician,\n It's time for you to buckle up and get ready for some intense arithmetic action\n";
    cout << "\nSelect mode of game" << endl;
    cout << " 1. Quiz Time" << endl;
    cout << " 2. Time bound practice" << endl;
    cout << " 3. Long Challenge" << endl;
    cout << " 4. Instructions" << endl;
    cout << " 5. Bored?? ->Exit" << endl;
}

void base_class::instructions()
{
    string str[3];
    str[0] = "Total time for the practice will be 1 minutes. For each correct submission 3 points will be rewarded, and for each wrong submission 1 point will be deducted.";
}

void base_class::operation()
{
    bool flag = false;
    while (!flag)
    {
        switch (op)
        {
        case 0:
        {
            Addition tmp;
            cout << "Loading Question...";
            this_thread::sleep_for(chrono::seconds(3));
            if (!tmp.repeat())
                flag = true;
        }
        }
    }
}

void base_class::time_exit(int sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    system("cls");

    /// <summary>
   /// TOdo
   /// class template
   /// 
   /// </summary>
}



void base_class::gotoxy(int x, int y)
{

    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void base_class::print_scores()
{
    gotoxy(100, 0);
    cout << "Scores : " << score;
    gotoxy(0, 0);
}
