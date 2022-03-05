#include "header.h"
using namespace std;

void home_teacher()
{
    string rept_teacher_to_admin(".//reports//teacher_to_admin.txt");
    string report;
    int choice;
    system("cls");

    gotoxy(5,3);
    cout<<"Teacher Home";
    gotoxy(10,5);
    cout<<"1.Set Continious Evolution Mark";
    gotoxy(10,6);
    cout<<"2.Veiw Students Info";
    gotoxy(10,7);
    cout<<"3.Make a report";

    gotoxy(10,13);
    cout<<"Enter your choice: ";
    gotoxy(40,13);
    cin>>choice;

    if(choice==3)
    {
        system("cls");
        gotoxy(5,3);
        cout<<"Teacher Home :: Make a Report";

            fstream file;
            file.open(rept_teacher_to_admin,std::ios_base::app);
            if(file.is_open())
            {
               system("cls");
               gotoxy(10,15);
               cout<<"Type your report: ";
               gotoxy(40,12);
               getline(cin>>ws,report);  //modification needed for line
               file<<report;

                cout<<"Report Successfully Sent";
            }
        }
}
