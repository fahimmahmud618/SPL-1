#include "header.h"
using namespace std;

void add_student()
{
    int choice,batch_serial,student_number,i,new_student_id;
    string makefilename;
    char* filename;

    system("cls");
    gotoxy(7,3);
    cout<<"Admin :: Add Student";

    gotoxy(10,5);
    cout<<"1.Add Batchwise";
    gotoxy(10,6);
    cout<<"2.Add personally";

    gotoxy(15,9);
    cout<<"Enter your choice: ";
    cin>>choice;

    system("cls");
    gotoxy(7,3);
    cout<<"Admin :: Add Student :: Add Batchwise";
    if(choice==1)
    {

        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(10,6);
        cout<<"Total student in the batch";

        gotoxy(40,5);
        cin>>batch_serial;

        makefilename=".//studentData//batch"+to_string(batch_serial);
        filename=&makefilename[0];
        mkdir(filename);

        gotoxy(40,6);
        cin>>student_number;

        for(i=1;i<=student_number;i++)
        {
            if(i<10)
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+"0"+to_string(i)+".txt";
            else
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+to_string(i)+".txt";
            ofstream out(makefilename);
        }

    }
    else if(choice==2)
    {
        gotoxy(10,5);
        cout<<"Enter Batch Serial: ";

        gotoxy(10,6);
        cout<<"Enter New Student's ID: ";
        
        gotoxy(40,5);
        cin>>batch_serial;
        
        gotoxy(40,6);
        cin>>new_student_id;
        
        if(i<10)
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+"0"+to_string(i)+".txt";
            else
                makefilename=".//studentData//batch"+to_string(batch_serial)+"//"+to_string(batch_serial)+to_string(i)+".txt";
            ofstream out(makefilename);
        
    }
}

