#include "header.h"
using namespace std;

void home_admin_control_student()
{
    int choice,i,batch_serial,student_id;
    string window_option[10];

    basic_window();
    window_option[0]="Add Student";
    window_option[1]="Modify Student";
    window_option[2]="Delete Student";
    window_option[3]="View Student's Info";

    choice = option_input_on_window(window_option,4);

    if(choice==1)
    {
        add_student();
    }
    else if(choice==2)
    {
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
        //invalid_choice_flag=1;
        delete_student();
    }
    else if(choice==4)
    {
        //invalid_choice_flag=1;
        view_student_info();
    }
    else
    {
       //invalid_choice_flag=0;
       home_admin_control_student();

    }
}

void add_student()
{
    int choice,batch_serial,student_number,i,new_student_id;
    string makefilename;
    string window_option[10];
    char* filename;

    /*basic_window();
    window_option[0]="Add Batchwise";
    window_option[1]="Add personally";

    choice = option_input_on_window(window_option,2);*/

    if(two_confirmation_popup("How do you want to add?","Add Batchwise","Add Personally"))
    {
        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(10,6);
        cout<<"Total student in the batch: ";

        gotoxy(40,5);
        cin>>batch_serial;

        makefilename=".//studentData//batch"+to_string(batch_serial);
        filename=&makefilename[0];
        mkdir(filename);

        gotoxy(40,6);
        cin>>student_number;

        for(i=1;i<=student_number;i++)
        {
            if(i<10)
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+"0"+to_string(i)+".txt";
            else
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+to_string(i)+".txt";
            ofstream out(makefilename);
            out << "No information";
        }

    }
    else
    {
        cout<<"Admin :: Student Control :: Add Student :: Add Personally";
        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(10,6);
        cout<<"Enter New Student's ID: ";

        gotoxy(40,5);
        cin>>batch_serial;

        gotoxy(40,6);
        cin>>new_student_id;

        if(new_student_id<10)
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+"0"+to_string(new_student_id)+".txt";
            else
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+to_string(new_student_id)+".txt";
    }
}

void register_student(string student_file)
{
    ofstream out(student_file);

}
