#include "header.h"
using namespace std;

void home_teacher(string teacher_id)
{
    string rept_teacher_to_admin(".//reports//teacher_to_admin.txt");
    string report;
    int choice;

    string window_option[10];
    basic_window();
    window_option[0]="Set Continious Evolution Mark";
    window_option[1]="Set Assignment";
    window_option[2]="Veiw Students Info";
    window_option[3]="Make a report";
    window_option[4]="Change Password";

    choice = option_input_on_window(window_option,5,1);

    if(choice==4)
    {
        system("cls");
        gotoxy(5,3);
        cout<<"Teacher Home :: Make a Report";

        fstream file;
        file.open(rept_teacher_to_admin,std::ios_base::app);
        if(file.is_open())
        {
            report = taking_report();
            file<<report<<endl;
            file.close();

            confirmation_popup("Report/Query sent succcesfully");
        }
    }
    if(choice==1)
    {
        update_continious_evolution_mark(teacher_id);
    }
    else if(choice==2)
    {
        string batch_serial;
        basic_window();
        cout<<"Enter Batch Serial";
        cin>>batch_serial;
        set_assignment(batch_serial);
    }
    else if(choice==3)
    {
        view_student_info();
    }
    else if(choice==5)
    {
        change_password(teacher_id,"2");
    }
}
