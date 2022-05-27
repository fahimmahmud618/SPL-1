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

int convert_stringToNumber(string s)
{
    int num = 0;
    int n = calc_string_len(s);

    for (int i = 0; i < n; i++)
        num = num * 10 + (int(s[i]) - 48);

    return num;
}

int string_to_number(string taken_string)
{
    double num;
    num = stoi(taken_string);
    return num;
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

bool if_contains_other_char(string given_string)
{
    int i,length = calc_string_len(given_string);

    for(i=0;i<length;i++)
    {
        if(((given_string[i]>='a')&&(given_string[i]<='z'))||((given_string[i]>='A')&&(given_string[i]<='Z'))||((given_string[i]>='0')&&(given_string[i]<='9')))
            continue;
        else
            break;
    }
    if(i==length)
        return true;
    else
        return false;
}


