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
    if(in)
    {
        gotoxy(90,8);
        for(semester_count=0;semester_count<8;semester_count++)
    {
        for(course_count=0;course_count<6;course_count++)
        {
            getline(in2,line);
            a1.semesters[semester_count].courses[0].course_name=line;
            cout<<line<<endl;
            if(semester_count==6)
                break;
        }
    }
        cout<<"ok";

    }
    else
    {
        gotoxy(90,8);
        cout<<"There is no such student";
    }
}
