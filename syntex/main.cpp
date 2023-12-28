#include <iostream>
#include <conio.h>
using namespace std;

int i = 0;
char s[10];

void S();
void A();
void disp();
void error();

int main()
{
    cout << "Given grammar is " << endl;
    cout << "S -> Ab" << endl;
    cout << "S -> aAb" << endl;
    cout << "A -> a" << endl;

    cout << "Enter the string" << endl;
    cin >> s;
    S();

    if (s[i] == '\0')
        cout << "String is valid" << endl;
    else
        cout << "String is invalid" << endl;

    getch();
    return 0;
}

void S()
{
    if (s[i] == 'a')
    {
        i++;

        if (s[i] == 'b')
            i++;
        else if (s[i]=='a')
        {
            A();
            if (s[i] == 'b')
                i++;
        }
        else
            error();
    }
    else
    {
        error();
    }
}

void A()
{
    if (s[i] == 'a')
    {
        i++;
    }
    else
    {
        error();
    }
}

void error()
{
    cout << "String is invalid" << endl;
    getch();
    exit(0);
}
