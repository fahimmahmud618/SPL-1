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
        cout<<"Student Name: "<<name<<endl<<"ID: "<<id<<endl<<"Address: "<<address<<endl<<endl;
    }

    void read_data()
    {
        cout<<"Enter name: ";
        cin>>name;

        cout<<"Enter id: ";
        cin>>id;

        cout<<"Enter address: ";
        cin>>address;

    }
    void storedata()
    {
        ofstream out("sample.dat",ios::binary);
        if(out)
        {
            out.write((char*)this,sizeof(*this));
            out.close();
        }
        else
            cout<<"noooooo";

    }
    void viewdata()
    {
        ifstream in("sample.dat",ios::binary);
        //in.seekg(sizeof(*this));
        //cout<<"___"<<in.tellg();
        in.read((char*)this,sizeof(*this));
        display();


        in.close();
    }

};


int main()
{
    char word;
    int t;
    //ofstream f("sample.txt");
    student s1,s2,s3;
    //s1.read_data();
    //s2.read_data();
    //s3.read_data();
    //s1.viewdata();

    s2.viewdata();
    s3.viewdata();
    /*while(f.tellg()<7)
    {
        if(f.tellg()>3)
        {f>>noskipws>>word;
        cout<<word;}
        //cout<<"__"<<f.tellg()<<"__";
    }*/



}
