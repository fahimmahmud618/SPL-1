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

bool encrypt(string taken_file)
{
    char ch,oldname[]="temp" ;
    char* newname=&taken_file[0];
    int t;
    ifstream input;
    ofstream output;

    input.open(taken_file, ios:: binary);
    output.open("temp",ios::binary);

    if((input)&&(output))
    {
        while(!input.eof())
        {
            input>>noskipws>>ch;
            t=ch+100;
            output<<(char)t;
        }
        input.close();
        output.close();
        remove(&taken_file[0]);
        rename(oldname,newname);

        return true;
    }
    else
        return false;
}

bool decrypt(string taken_file)
{
    char ch,oldname[]="temp" ;
    char* newname=&taken_file[0];
    int t;
    ifstream input;
    ofstream output;

    input.open(taken_file, ios:: binary);
    output.open("temp",ios::binary);

    if((input)&&(output))
    {
        while(!input.eof())
        {
            input>>noskipws>>ch;
            t=ch-100;
            output<<(char)t;
        }
        input.close();
        output.close();
        remove(&taken_file[0]);
        rename(oldname,newname);

        return true;
    }
    else
        return false;
}
