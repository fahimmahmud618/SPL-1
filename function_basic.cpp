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

string convert_numberToString(int number)
{
    int n = INT_MIN;
    char buffer[50];
    int i = 0;

    bool isNeg = n<0;

    unsigned int n1 = isNeg ? -n : n;

    while(n1!=0)
    {
        buffer[i++] = n1%10+'0';
        n1=n1/10;
    }

    if(isNeg)
        buffer[i++] = '-';

    buffer[i] = '\0';

    for(int t = 0; t < i/2; t++)
    {
        buffer[t] ^= buffer[i-t-1];
        buffer[i-t-1] ^= buffer[t];
        buffer[t] ^= buffer[i-t-1];
    }

    if(n == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
    }

    printf(buffer);

}

double string_to_number(string taken_string)
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
