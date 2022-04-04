#include "header.h"
using namespace std;

void home_student()
{
    string rept_stu_to_admin(".//reports//student_to_admin.txt");
    string report;
    int choice;

    string window_option[10];
    basic_window();
    window_option[0]="Veiw your Info";
    window_option[1]="Make a query";

    choice = option_input_on_window(window_option,2,1);

    if(choice==2)
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
