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

    void read_data()
    {
        cout<<"Enter Name : ";
        getline(cin>>ws,name);
        
        cout<<"Enter Enter ID : ";
        getline(cin>>ws,id);
        
        cout<<"Enter Address : ";
        getline(cin>>ws,address);
        
        cout<<"Enter Age : ";
        cin>>age;
        
    }
    
    person(string Name, string Id, string Address, int Age)
    {
        name= Name;
        Id= id;
        address=Address;
        age=Age;
    }

    void displayInformation()
    {
        cout<<"Name is : "<<name;
        cout<<"ID : "<<id;
        cout<<"Address : "<<address;
        cout<<"Age : "<<age;
    }

};


#endif // PERSON_H_INCLUDED
