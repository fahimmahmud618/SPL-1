#include "header.h"
using namespace std;

void home_admin_control_teacher()
{
    int choice;
    string makefilename,teacher_id;
    char* filename;

    system("cls");
    gotoxy(5,3);
    cout<<"Admin :: Teacher Control";

    gotoxy(10,5);
    cout<<"1.Add Teacher";
    gotoxy(10,6);
    cout<<"2.Modify Teacher";
    gotoxy(10,7);
    cout<<"3.Delete Teacher";
    gotoxy(10,8);
    cout<<"4.View Teacher's Info";

    gotoxy(15,10);
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice==1)
    {
        system("cls");
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
        system("cls");
        gotoxy(10,5);
        cout<<"Enter New Teacher's ID: ";           //modification
        gotoxy(40,5);
        cin>>teacher_id;
        makefilename=".//teacherData//"+teacher_id+".txt";

        filename=&makefilename[0];

        //cout<<filename;
        if(remove(filename)==0)
        {
            cout<<"The Teacher removed Succecfully";
        }
        else
            cout<<"Couldn't remove the teacher";
    }
}
