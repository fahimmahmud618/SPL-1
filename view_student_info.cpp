#include "header.h"
using namespace std;

void view_student_info()
{
    int batch_serial, student_id,choice;
    string makefilename;
    char* filename;

    system("cls");
    gotoxy(5,3);
    cout<<"Admin :: Student Control :: View Student's Info";

    gotoxy(10,5);
    cout<<"1.Batch wise Info";
    gotoxy(10,6);
    cout<<"2.Student in-person info";

    gotoxy(15,9);
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice==1)
    {
        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(40,5);
        cin>>batch_serial;

        makefilename=".//studentData//batch"+to_string(batch_serial);
        filename=&makefilename[0];
    }
}
