#include "header.h"
using namespace std;

void home_admin()
{
    person p;

    int choice,invalid_choice_flag=1;

    string window_option[10];
    basic_window();
    //p.SetInformation();
    //p.displayInformation();
    window_option[0]="Control Teacher";
    window_option[1]="Control Student";
    window_option[2]="Reports";

    choice = option_input_on_window(window_option,3,1);

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
    string window_option[10],filename;

    basic_window();
    window_option[0]="Reports from teacher";
    window_option[1]="Reports from students";

    choice = option_input_on_window(window_option,2,2);

    ifstream file;
    if(choice==1)
        filename=".//reports//teacher_to_admin.txt";
    else if(choice==2)
        filename=".//reports//student_to_admin.txt";


    file.open(filename);
    if(file)
        {
            basic_window();
            string line_in_file;
            gotoxy(2,5);
            cout<<"Reports for you: "<<endl;
            int i=7;
            while(getline(file,line_in_file))
            {
                gotoxy(2,i);
                cout<<i-6<<". "<<line_in_file;
                i++;
            }
        }
}
