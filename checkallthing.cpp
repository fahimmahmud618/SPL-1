#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
class student{
public:
    char name[30];
    char id[4];
    char address[30];

    void display()
    {
        cout<<"Student Name: "<<name<<endl<<"ID: "<<id<<endl<<"Address: "<<address;
    }

    void read()
    {
        cout<<"Enter name: ";
        cin>>name;

        cout<<"Enter id: ";
        cin>>id;

        cout<<"Enter address: ";
        cin>>address;

    }
};
int main()
{
    char word;
    fstream f("student.dat",ios::binary);

    //cout<<f.tellg();
    //student s1("fahim","1231","chuadanga");

    student s1;
    s1.read();


    f.write((char*)&s1,sizeof(s1));

    fstream r("student.dat",ios::binary);
    r.read((char*)&s1,sizeof(s1));
    s1.display();
    /*while(f.tellg()<7)
    {
        if(f.tellg()>3)
        {f>>noskipws>>word;
        cout<<word;}
        //cout<<"__"<<f.tellg()<<"__";
    }*/



}
