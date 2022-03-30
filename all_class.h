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
        int attendance_cout;
        float assignment_mark;
        string course_name;

        course()
        {
            class_test=0;
            midterm_mark=0;
            continious_evolution_total_mark=0;
            final_mark=0;
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
    string contract_num;
    string mail_add;

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
/*float class_test;
        float midterm_mark;
        float continious_evolution_total_mark;
        float final_mark;*/

class student:public person,public academic
{

public:
    //academic a;
    int current_semister;
    int batch_serial;
    float cgpa;
    //float academic_mark[8][6][6];

    student(string filename, string taken_id,int given_current_semister)
    {
        int i,j,k;
        name="No name";
        address="Unknown/no data";
        age=0;
        id=taken_id;
        current_semister= given_current_semister;
        mail_add="No information";
        contract_num="NO information";
        ofstream out(filename,ios::binary);
        out.write((char*)this,sizeof(*this));
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

    void upadate_continious_evolution_mark(string filename, float mark,int semister_num, int course_num)
    {
        ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            semesters[semister_num].courses[course_num].continious_evolution_total_mark += mark;
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

    string view_student_basic_info_file(string filename)
    {
       ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            return to_string(batch_serial)+" "+id+" "+name+" "+to_string(current_semister)+" "+to_string(cgpa)+" "+contract_num+" "+mail_add;
            in.close();
        }
    }

    string view_student_course_condition(string filename, int semister_num, int course_num)
    {
        ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));     //gpa have to be added
            return id+"\t"+name+"\t"+to_string(semesters[semister_num].courses[course_num].attendance_cout)+"\t"+to_string(semesters[semister_num].courses[course_num].class_test)+"\t"+to_string(semesters[semister_num].courses[course_num].midterm_mark)+"\t"+to_string(semesters[semister_num].courses[course_num].final_mark);
            in.close();
        }
    }

    string view_student_semister_contdition(string filename, int semister_num)
    {
        string course_number_string ="Course Numbers: ";
        for(int i=0; i<6;i++)
            course_number_string = course_number_string +" "+to_string(semesters[semister_num].courses[i].final_mark);

        ifstream in(filename,ios::binary);
        if(in)
        {
            in.read((char*)this,sizeof(*this));
            return id+"\t"+name+"\n"+course_number_string;   //cga have to be addded and other things
            in.close();
        }

    }
};

class teacher:public person
{
public:
    student s1;
};

#endif // ALL_CLASS_H_INCLUDED
