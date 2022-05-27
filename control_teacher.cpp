#include "header.h"
//using namespace std;

void home_admin_control_teacher()
{
    int choice;
    string makefilename,teacher_id;
    char* filename;

    string window_option[10];
    basic_window();
    window_option[0]="Add Teacher";
    window_option[1]="Modify Teacher";
    window_option[2]="Delete Teacher";
    window_option[3]="View Teacher's Info";

    choice = option_input_on_window(window_option,4,1);

    if(choice==1)
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter New Teacher's ID: ";
        gotoxy(40,5);
        cin>>teacher_id;
        makefilename=".//teacherData//"+teacher_id+".dat";
        teacher t(makefilename,teacher_id);
    }
    else if(choice==3)
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter New Teacher's ID: ";           //modification
        gotoxy(40,5);
        cin>>teacher_id;
        makefilename=".//teacherData//"+teacher_id+".dat";

        filename=&makefilename[0];

        //cout<<filename;
        if(remove(filename)==0)
        {
            confirmation_popup("The Teacher removed Succecfully");
        }
        else
            confirmation_popup("Couldn't remove the teacher");

    }
    else if(choice==2)
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter the teacher;s id: ";

        gotoxy(40,5);
        cin>>teacher_id;
        edit_teacher_basic_info(teacher_id);
    }
    else if(choice==4)
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter the teacher;s id: ";

        gotoxy(40,5);
        cin>>teacher_id;
        view_teacher_info_func(teacher_id);
    }
}

void edit_teacher_basic_info(string teacher_id)
{
    string filename = ".//teacherData//"+teacher_id+".dat",window_option[10];
    if(check_file_if_exits(filename,".//teacherData"))
    {
        teacher t;
        window_option[0]="Enter teacher name: ";
        window_option[1]="Enter teacher's age: ";
        window_option[2]="Enter teacher's address: ";
        window_option[3]="Enter teacher's mail-address: ";
        window_option[4]="Enter teacher's contract-num: ";

        vector<string> inputs = taking_list_input_on_window(window_option,5,2);
        t.set_Teacher_info_basic(filename,inputs[0],inputs[2],stoi(inputs[1]),inputs[3],inputs[4]);
        confirmation_popup("Record saved successfully");
    }
    else
        confirmation_popup("No such teacher found");

}

void view_teacher_info_func(string teacher_id)
{
    teacher t;
    if(teacher_id=="All")
    {
            vector<string> files = list_of_files(".//teacherData");
            for(auto teacher_file : files)
                cout<<t.view_teacher_info(".//teacherData"+teacher_file)<<endl;
    }
    else
    {
        string filename = ".//teacherData"+teacher_id+".dat";
        cout<<t.view_teacher_info(filename)<<endl;
    }

}
