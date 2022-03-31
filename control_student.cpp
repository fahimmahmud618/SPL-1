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

    choice = option_input_on_window(window_option,4,1);

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
        delete_student();
    }
    else if(choice==4)
    {
        view_student_info();
    }
    else
    {
       home_admin_control_student();

    }
}

void add_student()
{
    int choice,batch_serial,student_number,i,semister_num,student_id;
    string new_student_id;
    bool dis=true;
    string makefilename;
    string window_option[10];
    char* filename;

    if(two_confirmation_popup("How do you want to add?","Add Batchwise","Add Personally"))
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(10,6);
        cout<<"Total student in the batch: ";

        gotoxy(10,7);
        cout<<"Student's semister num: ";

        gotoxy(40,5);
        cin>>batch_serial;

        gotoxy(40,6);
        cin>>student_number;

        gotoxy(40,5);
        cin>>semister_num;

        makefilename=".//studentData//batch"+to_string(batch_serial);
        filename=&makefilename[0];
        mkdir(filename);

        for(i=1;i<=student_number;i++)
        {
            if(i<10)
                new_student_id=to_string(batch_serial)+"//"+to_string(batch_serial)+"0"+to_string(i)+".dat";
            else
                new_student_id=to_string(batch_serial)+"//"+to_string(batch_serial)+to_string(i)+".dat";

            makefilename=".//studentData//batch"+new_student_id;

            register_student(makefilename,new_student_id,semister_num);
        }
            if(dis)
                confirmation_popup("All the student is registered");
            else
                confirmation_popup("Something happend, couldn't register the batch");

    }
    else
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(10,6);
        cout<<"Enter New Student's ID: ";

        gotoxy(10,6);
        cout<<"Student's semister: ";

        gotoxy(40,5);
        cin>>batch_serial;

        gotoxy(40,5);
        cin>>new_student_id;

        gotoxy(40,6);
        cin>>semister_num;

        student_id = stoi(new_student_id);
        if(student_id<10)
                new_student_id=to_string(batch_serial)+"//"+to_string(batch_serial)+"0"+to_string(student_id)+".dat";
            else
                new_student_id=to_string(batch_serial)+"//"+to_string(batch_serial)+to_string(student_id)+".dat";

            makefilename=".//studentData//batch"+new_student_id;

        register_student(makefilename,new_student_id,semister_num);
    }
}

void register_student(string student_file, string student_id, int semister)
{
    student s(student_file, student_id, semister); //eta to etar header file git e update kora hoini
}
