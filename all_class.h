#ifndef ALL_CLASS_H_INCLUDED
#define ALL_CLASS_H_INCLUDED
#include "header.h"
using namespace std;
class person
{
public:
    string name;
    string id;
    string address;
    int age;

    person(string Name, string Id, string Address, int Age)
    {
        name= Name;
        Id= id;
        address=Address;
        age=Age;
    }

    void displayInformation()
    {
        cout<<name;
        cout<<id;
        cout<<address;
        cout<<age;
    }

};

class student:public person
{
    int current_semister;

};

class teacher:public person
{

};

class course
{
public:
        float assignment;
        float attendance;
        float class_test;
        float midterm_mark;
        float final_mark;
        string course_name;

    //calculate total in continious evolution
    float continious_evolution_total()
    {
        return assignment+attendance+class_test;
    }

    float course_total()
    {
        return continious_evolution_total()+midterm_mark+final_mark;
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

#endif // ALL_CLASS_H_INCLUDED
