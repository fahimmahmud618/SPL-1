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
    }

    for(i=4;i<=25;i++)
    {
        gotoxy(116,i);
        cout<<"|";
    }
}

int option_input_on_window(string *option_array, int size)
{
    int i,choice;
    for(i=5;i<(size+5);i++)
    {
        gotoxy(2,i);
        cout<<i-4<<". "<<option_array[i-5]<<endl;
    }

    gotoxy(1,i+1);
    cout<<"----------------";

    gotoxy(2,i+2);
    cout<<"Enter your choice: ";
    cin>>choice;

    return choice;
}
