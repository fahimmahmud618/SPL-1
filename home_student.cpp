#include "header.h"
using namespace std;

void home_student()
{
    string rept_stu_to_admin(".//reports//student_to_admin.txt");
    string report;
    int choice;
    system("cls");

    gotoxy(5,3);
    cout<<"Student Home";
    gotoxy(10,5);
    cout<<"1.Veiw your Info";
    gotoxy(10,6);
    cout<<"2.Make a query";

    gotoxy(10,12);
    cout<<"Enter your choice: ";
    gotoxy(40,12);
    cin>>choice;

    if(choice==2)
    {
        system("cls");
        gotoxy(5,3);
        cout<<"Student Home :: Make a query";
        gotoxy(10,5);
        cout<<"1.To the Admin";
        gotoxy(10,6);
        cout<<"2.To the course teacher";

        gotoxy(10,12);
        cout<<"Enter your choice: ";
        gotoxy(40,12);
        cin>>choice;

        if(choice==1)
        {
            ofstream file;
            file.open(".//reports//student_to_admin.txt",std::ios_base::app);
            if(file.is_open())
            {
               system("cls");
               gotoxy(10,15);
               cout<<"Type your report: ";
               gotoxy(40,15);
               getline(cin>>ws,report);
               cout<<"Report is:"<<report;
               file<<report<<endl;

               file.close();

                cout<<"Report Successfully Sent";
            }
        }
    }
}
