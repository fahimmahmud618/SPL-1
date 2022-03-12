#include "header.h"
using namespace std;

void home_admin()
{
    int choice,invalid_choice_flag=1;
    string window_option[10];

    basic_window();
    window_option[0]="Admin Home";
    window_option[1]="Control Teacher";
    window_option[2]="Control Student";
    window_option[3]="Reports";

    choice = option_input_on_window(window_option,4);

    if(choice==1)
    {
        home_admin_control_teacher();
    }
    else if(choice==2)
    {
        home_admin_control_student();
    }
    else if(choice==3)
    {
        home_admin_control_reports();
    }
    else
    {
       home_admin();
    }

}


void home_admin_control_reports()
{
    int choice;
    system("cls");

    gotoxy(5,3);
    cout<<"Admin Home :: Ve";
    gotoxy(10,5);
    cout<<"1.Reports from teacher";
    gotoxy(10,6);
    cout<<"2.Reports from students";

    gotoxy(10,12);
    cout<<"Enter your choice: ";
    gotoxy(40,12);
    cin>>choice;

    if(choice==1)
    {
        ifstream file(".//reports//teacher_to_admin.txt");
        if(file.is_open())
        {
            system("cls");
            string line_in_file;
            while(getline(file,line_in_file))
            {
                cout<<line_in_file<<endl;
            }
        }
    }

    if(choice==2)
    {
        ifstream file(".//reports//student_to_admin.txt");
        if(file.is_open())
        {
            system("cls");
            string line_in_file;
            while(getline(file,line_in_file))
            {
                cout<<line_in_file<<endl;
            }
        }
    }
}
