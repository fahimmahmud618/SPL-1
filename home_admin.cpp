#include "header.h"
using namespace std;

void home_admin()
{
    int choice,invalid_choice_flag=1;

    system("cls");
    gotoxy(10,5);
    cout<<"1.Control Teacher";
    gotoxy(10,6);
    cout<<"2.Control Student";
    gotoxy(10,7);
    cout<<"3.Reports";



    gotoxy(10,13);
    cout<<"Enter your choice: ";
    if(invalid_choice_flag==0)
    {
        gotoxy(10,15);
        cout<<"Please Enter a right choice: ";
    }
    gotoxy(40,13);
    cin>>choice;

    if(choice==1)
    {
        invalid_choice_flag=1;
        home_admin_control_teacher();
    }
    else if(choice==2)
    {
        invalid_choice_flag=1;
        home_admin_control_student();
    }
    else if(choice==3)
    {
        invalid_choice_flag=1;
        home_admin_control_reports();
    }
    else
    {
       invalid_choice_flag=0;
       home_admin();
    }

}

void home_admin_control_teacher()
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
    cout<<"4.View Teacher's Info";
}

void home_admin_control_student()
{
    int choice,invalid_choice_flag=1;

    system("cls");
    gotoxy(10,5);
    cout<<"1.Add Student";
    gotoxy(10,6);
    cout<<"2.Modify Student";
    gotoxy(10,7);
    cout<<"3.Delete Student";
    gotoxy(10,8);
    cout<<"4.View Student's Info";

    if(choice==1)
    {
        invalid_choice_flag=1;
        add_student();
    }
    else if(choice==2)
    {
        invalid_choice_flag=1;
        modify_student();
    }
    else if(choice==3)
    {
        invalid_choice_flag=1;
        delete_student();
    }
    else if(choice==4)
    {
        invalid_choice_flag=1;
        view_student_info();
    }
    else
    {
       invalid_choice_flag=0;
       home_admin_control_student();

    }
}

void home_admin_control_reports()
{

}
