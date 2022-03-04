#include "header.h"
using namespace std;

void modify_student(int batch_serial, int student_id)
{
    string filename =".//studentData//batch"+to_string(batch_serial)+"//"+to_string(student_id)+".txt";
    ifstream in;
    in.open(filename);

    string filename2 ="courses.txt";
    ifstream in2;
    in2.open(filename2);

    string line;
    int course_count=0,semester_count;
    academic a1;

    string student_name,student_address;
    int student_age,current_semester;
    float student_cgpa=0.00;

    system("cls");
    gotoxy(5,3);
    cout<<"Admin :: Student Control :: Edit Student's Info";
    if(in)
    {
        getline(in,line);
        if(line=="No information")
        {
            in.clear();
            system("cls");
            gotoxy(10,10);
            cout<<"Enter Student Name:";
            gotoxy(10,11);
            cout<<"Enter Student's Adddress:";
            gotoxy(10,12);
            cout<<"Enter Student's Age:";
            gotoxy(10,13);
            cout<<"Enter Student' current semester:";

            gotoxy(40,10);
            getline(cin,student_name);
            gotoxy(40,11);
            getline(cin,student_address);   //bug
            gotoxy(40,12);
            cin>>student_age;
            gotoxy(40,13);
            cin>>current_semester;

            cout<<"done";

            ofstream out(filename);
            out << student_name<<endl;
            out << student_address<<endl;
            out << student_age<<endl;
            out << current_semester<<endl;
            out << student_cgpa<<endl;


            for(semester_count=0;semester_count<8;semester_count++)
            {
                for(course_count=0;course_count<6;course_count++)
                {
                    getline(in2,line);
                    a1.semesters[semester_count].courses[0].course_name=line;
                    out <<line<<endl;
                    for(int i=0;i<7;i++)
                    {
                        out<<"0"<<endl;
                    }
                    //cout<<line<<endl;
                    if(semester_count==6)
                        break;
                }
            }
            cout<<"ok";
        }

    }
    else
    {
        gotoxy(90,8);
        cout<<"There is no such student";
    }
}
