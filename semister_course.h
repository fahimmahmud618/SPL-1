#ifndef SEMISTER_COURSE_H_INCLUDED
#define SEMISTER_COURSE_H_INCLUDED
#include "header.h"
using namespace std;

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

