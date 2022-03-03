#include "header.h"
using namespace std;

void home_admin()
{
    int choice;

    system("cls");
    gotoxy(10,5);
    cout<<"1.Add Teacher";
    gotoxy(10,6);
    cout<<"2.Modify Teacher";
    gotoxy(10,7);
    cout<<"3.Delete Teacher";

    gotoxy(10,8);
    cout<<"4.Add Student";
    gotoxy(10,9);
    cout<<"5.Modify Student";
    gotoxy(10,10);
    cout<<"6.Delete Student";


    gotoxy(15,13);
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice==1)
    {

    }
    else if(choice==2)
    {

    }
    else if(choice==3)
    {

    }
    else if(choice==4)
    {
        add_student();
    }
    else if(choice==5)
    {

    }
    else if(choice==6)
    {

    }

}
