#ifndef ALL_CLASS_H_INCLUDED
#define ALL_CLASS_H_INCLUDED
#include "header.h"
using namespace std;

class course
{
public:
        float class_test;
        float midterm_mark;
        float continious_evolution_total_mark;
        float final_mark;
        string course_name;

    //calculate total in continious evolution
    float set_continious_evolution_mark(string filename, float mark)
    {
        ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            continious_evolution_total_mark = continious_evolution_total_mark + mark;
            in.close();
        }
        else
            cout<<"Error happended";

        ofstream out(filename,ios::binary);
        if(out)
        {
            out.write((char*)this,sizeof(*this));
            out.close();
        }
        else
            cout<<"Error happended";
    }

    
    float make_course_total(string filename, float assignment_attendanceMark)
    {
        ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            final_mark = continious_evolution_total_mark + assignment_attendanceMark +midterm_mark;
            in.close();
        }
        else
            cout<<"Error happended";

        ofstream out(filename,ios::binary);
        if(out)
        {
            out.write((char*)this,sizeof(*this));
            out.close();
        }
        else
            cout<<"Error happended";
    }
    
    float ret_continious_evolution_total(string filename)
    {
        ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            return continious_evolution_total_mark;
        }
    }
    
    float ret_final_total(string filename)
    {
        ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            return final_mark;
        }
    }
};

class semester
{
public:
    course courses[6];
};
class academic
{
public:
    semester semesters[8];
};
class person
{
public:
    string name;
    string id;
    string address;
    int age;

    /*person(string Name, string Id, string Address, int Age)
    {
        name= Name;
        Id= id;
        address=Address;
        age=Age;
    }*/

    void displayInformation()
    {
        //basic_window();
        cout<<name;
        cout<<id;
        cout<<address;
        cout<<age;
    }
    void SetInformation()
    {
        cout<<"Name : ";
        getline(cin>>ws,name);
        cout<<"ID : ";
        cin>>id;
        cout<<"Address : ";
        getline(cin>>ws,address);
        cout<<"Age : ";
        cin>>age;

    }

};

class student:public person
{
    academic a;
public:
    int current_semister;


    student(string taken_id,int given_current_semister)
    {
        name="No name";
        address="Unknown/no data";
        age=0;
        id=taken_id;
        current_semister= given_current_semister;
    }

    void set_Student_info_basic(string taken_name, string taken_address, string taken_id, int taken_age, int taken_current_semister)
    {
        name=taken_name;
        address = taken_address;
        id=taken_address;
        age = taken_age;
        current_semister = taken_current_semister;
    }

    void promote_or_demote_student(string taken_student_filename,bool action)
    {
        ifstream in(taken_student_filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            if(action)
                current_semister++;
            else
                current_semister--;
        }
        else
            cout<<"Error happended";

        ofstream out(taken_student_filename,ios::binary);
        if(out)
        {
            out.write((char*)this,sizeof(*this));
            out.close();
        }
        else
            cout<<"Error happended";
    }
};

class teacher:public person
{
public:
    student s1;
};

#endif // ALL_CLASS_H_INCLUDED
