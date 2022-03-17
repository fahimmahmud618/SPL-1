#include "header.h"
using namespace std;

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

    choice = option_input_on_window(window_option,4);

    if(choice==1)
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter New Teacher's ID: ";
        gotoxy(40,5);
        cin>>teacher_id;
        makefilename=".//teacherData//"+teacher_id+".txt";
            ofstream out(makefilename);
            out << "No information";
    }
    else if(choice==3)
    {
        basic_window();
        gotoxy(10,5);
        cout<<"Enter New Teacher's ID: ";           //modification
        gotoxy(40,5);
        cin>>teacher_id;
        makefilename=".//teacherData//"+teacher_id+".txt";

        filename=&makefilename[0];

        //cout<<filename;
        if(remove(filename)==0)
        {
            confirmation_popup("The Teacher removed Succecfully");
        }
        else
            confirmation_popup("Couldn't remove the teacher");

    }
}
