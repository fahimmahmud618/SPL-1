#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
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


#endif // PERSON_H_INCLUDED
