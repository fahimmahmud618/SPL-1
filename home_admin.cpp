#include "header.h"
using namespace std;

void home_admin()
{
    int choice,invalid_choice_flag=1;

    system("cls");

    gotoxy(5,3);
    cout<<"Admin Home";
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


void home_admin_control_student()
{
    int choice,invalid_choice_flag=1,batch_serial,student_id;

    system("cls");
    gotoxy(10,5);
    cout<<"1.Add Student";
    gotoxy(10,6);
    cout<<"2.Modify Student";
    gotoxy(10,7);
    cout<<"3.Delete Student";
    gotoxy(10,8);
    cout<<"4.View Student's Info";

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
        add_student();
    }
    else if(choice==2)
    {
        invalid_choice_flag=1;
        gotoxy(50,5);
        cout<<"Enter batch serial of the student";
        gotoxy(50,6);
        cout<<"Enter the student id:";
        gotoxy(90,5);
        cin>>batch_serial;
        gotoxy(90,6);
        cin>>student_id;
        modify_student(batch_serial,student_id);
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

