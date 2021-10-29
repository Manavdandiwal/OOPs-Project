#include "base_class.h"
#include "Addition.h"

int base_class::random(int length)
{
    /// <summary>
    /// Random number generator of given length 
    /// </summary>
    /// <param name="length">length of th number</param>
    /// <returns></returns>
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

void base_class::print_main_menu()
{
    /// <summary>
    /// esnu main program ch lae k jaana ae
    /// </summary>
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
    /// <summary>
    /// to be completed
    /// </summary>
    string str[3];
    str[0] = "Total time for the practice will be 1 minutes. For each correct submission 3 points will be rewarded, and for each wrong submission 1 point will be deducted.";
}

void base_class::time_exit(int sec)
{
    /// <summary>
    /// time wait using mutithreading
    /// </summary>
    /// <param name="sec"></param>
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void base_class::gotoxy(int x, int y)
{
    /// <summary>
    /// change cursor position on the console
    /// </summary>
    /// <param name="x">x coor</param>
    /// <param name="y">y coord</param>
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void base_class::corr_comments()
{
}

void base_class::wrong_comments()
{
}

void base_class::print_scores()
{
    gotoxy(100, 0);
    cout << "Scores : " << score;
    gotoxy(0, 0);
}
