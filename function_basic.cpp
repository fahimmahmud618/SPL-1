#include "header.h"

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int calc_string_len(string input)
{
    int i;
    for(i=0;input[i]!='\0';i++);
    return i;
}

bool check_number_or_not(string input)
{
    int i;
    for(i=0;i<calc_string_len(input);i++)
    {
        if(isdigit(input[i])==false)
            return false;
    }
    return true;
}

