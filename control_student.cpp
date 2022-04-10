#include "header.h"
using namespace std;

void home_admin_control_student()
{
    int choice,i;
    string batch_serial,student_id;
    vector<string> inputs;
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
        window_option[0]="Enter batch serial of the student: ";
        window_option[1]="Enter the student id: ";
        inputs = taking_list_input_on_window(window_option,2,2);

        batch_serial=inputs[0];
        student_id=inputs[1];
        //modify_student(batch_serial,student_id);
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
    int choice,student_id,num_student,i;
    string batch_serial,student_number,semister_num,new_student_id;
    bool dis=true;
    string makefilename,window_option[10];
    vector<string> inputs;
    char* filename;

    if(two_confirmation_popup("How do you want to add?","Add Batchwise","Add Personally"))
    {
        basic_window();
        window_option[0]="Enter Batch Serial: ";
        window_option[1]="Total student in the batch: ";
        window_option[2]="Student's semister num: ";
        inputs=taking_list_input_on_window(window_option,3,2);

        batch_serial=inputs[0];
        student_number=inputs[1];
        semister_num=inputs[2];

        makefilename=".//studentData//batch"+batch_serial;
        filename=&makefilename[0];
        mkdir(filename);

        num_student=stoi(student_number);
        for(i=1;i<=num_student;i++)
        {
            if(i<10)
                new_student_id=batch_serial+"//"+batch_serial+"0"+to_string(i)+".dat";
            else
                new_student_id=batch_serial+"//"+batch_serial+to_string(i)+".dat";

            makefilename=".//studentData//batch"+new_student_id;

            register_student(makefilename,new_student_id,stoi(semister_num));
        }
            if(dis)
                confirmation_popup("All the student is registered");
            else
                confirmation_popup("Something happend, couldn't register the batch");

    }
    else
    {
        basic_window();
        window_option[0]="Enter Batch Serial: ";
        window_option[1]="Enter New Student's ID: ";
        window_option[2]="Student's semister num: ";
        inputs=taking_list_input_on_window(window_option,3,2);

        batch_serial=inputs[0];
        new_student_id=inputs[1];
        semister_num=inputs[2];

        student_id = stoi(new_student_id);
        if(student_id<10)
                new_student_id=batch_serial+"//"+batch_serial+"0"+new_student_id+".dat";
            else
                new_student_id=batch_serial+"//"+batch_serial+new_student_id+".dat";

            makefilename=".//studentData//batch"+new_student_id;

        register_student(makefilename,new_student_id,stoi(semister_num));
    }
}

void register_student(string student_file, string student_id, int semister)
{
    student s(student_file, student_id, semister); //eta to etar header file git e update kora hoini
}

void delete_student()
{
    string batch_serial, student_id;
    int choice;
    string makefilename;
    vector<string> inputs;
    char* filename;

    string window_option[10];

    basic_window();
    window_option[0]="Remove Batchwise";
    window_option[1]="Remove Personally";

    choice = option_input_on_window(window_option,2,2);

    if(choice==1)
    {
        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(40,5);
        cin>>batch_serial;

        makefilename=".//studentData//batch"+batch_serial;
        filename=&makefilename[0];
        cout<<filename;                 //bug
        if(rmdir(filename)==0)
        {
            confirmation_popup("Batch removed Succecfully");
        }
        else
            confirmation_popup("Couldn't remove the Batch");
    }

    else if(choice==2)
    {
        window_option[0]="Enter Batch Serial: ";
        window_option[1]="Enter Student's ID: ";

        inputs = taking_list_input_on_window(window_option,2,2);
        batch_serial=inputs[0];
        student_id=inputs[1];

        if(stoi(student_id)<10)
                makefilename=".//studentData//batch"+batch_serial+"//"+student_id+".dat";
        else
                makefilename=".//studentData//batch"+batch_serial+"//"+student_id+".dat";
        filename=&makefilename[0];

        cout<<filename;
        if(remove(filename)==0)
        {
            confirmation_popup("Student removed Succecfully");
        }
        else
            confirmation_popup("Couldn't remove Student");

    }

}

void update_continious_evolution_mark(string person_id)
{
    string window_option[100];
    int i=0;
    basic_window();
    vector<int> choice=ret_selected_course_num(ret_selected_course_of_teacher(person_id));
    vector<string> student_files;
    student s;

    string batch_serial = ret_batchSerial(to_string(choice[0]));
    string filename = ".//studentData//"+batch_serial, temp_string;      //modification needed

    if(two_confirmation_popup("How do you want to update the mark?","Batchwise","Personally"))
    {
        cout<<filename;
        student_files  = list_of_files(filename);
        for(auto student_file : student_files)
        {
            window_option[i]="Enter mark for student "+student_file;
            i++;
        }
        vector<string> taken_marks = taking_list_input_on_window(window_option,i,1);
        for(i=0;i<student_files.size();i++)
        {
            temp_string = filename+student_files[i];
            s.upadate_continious_evolution_mark(temp_string,stof(taken_marks[i]),choice[0],choice[1]);

        }
        /*for((auto student_file1 : student_files)&&( auto mark : taken_marks))
        {
            s.upadate_continious_evolution_mark(student_file1,stof(mark),choice[0],choice[1]);
        }*/
        //s.upadate_continious_evolution_mark(func_makeFilename("12","1201"),2.3,choice[0],choice[1]);
    }
    else
    {
        basic_window();
        color(7);
        window_option[0]="Enter roll no: ";
        window_option[1]="Enter mark: ";
        vector<string> inputs = taking_list_input_on_window(window_option,2,2);
        filename = filename+"//"+inputs[0]+".dat";
        s.upadate_continious_evolution_mark(filename,stof(inputs[1]),choice[0],choice[1]);
    }

}
