#include "header.h"
using namespace std;

void home_student(string studentID)
{
    string student_filename = retfileNameFromID(studentID);
    string rept_stu_to_admin(".//reports//student_to_admin.txt");
    string report;
    int choice;

    string window_option[10];
    basic_window();
    window_option[0]="Veiw your Info";
    window_option[1]="Veiw assignment";
    window_option[2]="Make a query";
    window_option[3]="Change Password";

    choice = option_input_on_window(window_option,3,1);

    if(choice==3)
    {
        string window_option[10];
        //basic_window();
        window_option[0]="To the Admin";
        window_option[1]="To the course teacher";

        choice = option_input_on_window(window_option,2,2);

        if(choice==1)
        {
            ofstream file;
            file.open(".//reports//student_to_admin.txt",std::ios_base::app);
            if(file.is_open())
            {
               report = taking_report();
               file<<report<<endl;

               file.close();

                confirmation_popup("Report/Query sent succcesfully");
            }
        }

        if(choice==2)
        {
            ofstream file;
            file.open(".//reports//student_to_teacher.txt",std::ios_base::app);
            if(file.is_open())
            {

               report = taking_report();
               file<<report<<endl;

               file.close();

                confirmation_popup("Report/Query sent succcesfully");
            }
        }

    }
    if(choice==1)
    {
        int course_count;
        basic_window();
        student s;
        cout<<s.view_student_basic_info_file(student_filename);
        for(course_count=0;course_count<6;course_count++)
        cout<<s.view_student_course_condition(student_filename,s.ret_current_semsister(student_filename),course_count);
        cout<<s.view_student_semister_contdition(student_filename,s.ret_current_semsister(student_filename));
    }
    if(choice==2)
    {
        int i;
        string filename = ".//studentData//batch12//assignment.txt";

        fstream file;
        file.open(filename);
        if(file)
            {
                basic_window();
                string line_in_file;
                gotoxy(2,5);
                cout<<"Assignments for you: "<<endl;
                int i=7;
                while(getline(file,line_in_file))
                {
                    gotoxy(2,i);
                    cout<<i-6<<". "<<line_in_file;
                    i++;
                }
            }
    }
    else if(choice==4)
    {
        change_password(studentID,"3");
    }
}

string taking_report()
{
    string report;

    system("cls");
    gotoxy(10,15);
    cout<<"Type your report: ";
    gotoxy(40,15);
    getline(cin>>ws,report);

    return report;
}
