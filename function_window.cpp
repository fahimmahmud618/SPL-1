#include "header.h"
using namespace std;

void basic_window()
{
    int i;

    system("cls");
    cout<<" ___________________________________________________________________________________________________________________"<<endl;
    cout<<"|                                                   Teach Manager                                                   |"<<endl;
    cout<<"|___________________________________________________________________________________________________________________|"<<endl;
    cout<<"|___________________________________________________________________________________________________________________|"<<endl;
    gotoxy(0,26);
    cout<<"|___________________________________________________________________________________________________________________|"<<endl;

    for(i=4;i<=25;i++)
    {
        gotoxy(0,i);
        cout<<"|";
        gotoxy(116,i);
        cout<<"|";
    }
}

int option_input_on_window(string *option_array, int size, int side)
{
    int i,c,x_co;
    if(side==1)
        x_co=2;
    else if(side==2)
        x_co=50;
    string choice;
    int counter =1;
    for(;;)
    {
        for(i=5;i<(size+5);i++)
        {
            gotoxy(x_co,i);
            if((i-4)==counter)
                color(12);
            else
                color(7);
            cout<<i-4<<". "<<option_array[i-5]<<endl;
        }
        char key = _getch();

        if((key==72)&&(counter>1))
            counter--;
        else if((key==80)&&(counter<size))
            counter++;
        else if(key=='\r')
        {
            color(7);
            return counter;
        }
    }
}

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

bool two_confirmation_popup(string title, string option1, string option2)
{
    int total_string_length = calc_string_len(option1)+calc_string_len(option2);
    int i=116/2;
    int set[2];
    int select=1;
    char key;

    int j = i-total_string_length/2;

    gotoxy(j+1,13);
    cout<<"Pop up: "<<title;
    for(i=j;i<=j+(total_string_length+15);i++)
    {
        gotoxy(i,12);
        cout<<"_";
        gotoxy(i,18);
        cout<<"_";
    }
    for(i=13;i<=18;i++)
    {
        gotoxy(116/2-total_string_length/2,i);
        cout<<"|";
        gotoxy(j+(total_string_length+15),i);
        cout<<"|";
    }
   for(;;)
        {
            //system("cls");
        if(select==1)
        {
            set[0]=12;
            set[1]=7;
        }
        else
        {
            set[0]=7;
            set[1]=12;
        }
    //cout<<"new"<<endl;
        color(set[0]);
        gotoxy(j+5,16);
        cout<<option1;

        color(set[1]);
        gotoxy(j+10+calc_string_len(option1),16);
        cout<<option2;

        key=_getch();

        if((key=='\r')&&(select==1))
            return true;
        else if((key=='\r')&&(select==2))
            return false;

        if(select==1)
        {
            if(key==77)
                select=2;
            else
                select=1;
        }
        else
        {
            if(key==75)
                select=1;
            else
                select=2;
        }
    }
}

bool confirmation_popup(string title)
{
    int total_string_length = calc_string_len(title);
    int i=116/2;

    int j = i-total_string_length/2;

    for(i=j;i<=j+(total_string_length+10);i++)
    {
        gotoxy(i,12);
        cout<<"_";
        gotoxy(i,18);
        cout<<"_";
    }
    for(i=13;i<=18;i++)
    {
        gotoxy(116/2-total_string_length/2,i);
        cout<<"|";
        gotoxy(j+(total_string_length+10),i);
        cout<<"|";
    }
    gotoxy(j+5,16);
    cout<<title;
}

vector<string> taking_list_input_on_window(string *option_array, int size, int side)
{
    vector<string> inputs;
    string input;

    int i,c,x_co;
    if(side==1)
        x_co=2;
    else if(side==2)
        x_co=50;
    string choice;
    int counter =1;

    for(i=5;i<(size+5);i++)
        {
            gotoxy(x_co,i);
            cout<<option_array[i-5]<<endl;
        }

    x_co = x_co + 30;

    for(i=5;i<(size+5);i++)
        {
            gotoxy(x_co,i);
            cin>>input;
            inputs.push_back(input);
        }
    return inputs;
}
