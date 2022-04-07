#include "header.h"
using namespace std;

void login()
{
    string id, password;
    string personType, personNickName, personID, personPassword;

    basic_window();
    gotoxy(15,10);
    cout<<"Enter Your User ID: "<<endl;

    gotoxy(15,11);
    cout<<"Enter Your Password: "<<endl;

    gotoxy(38,10);
    cin>>id;

    gotoxy(38,11);
    cin>>password;

    ifstream in("userlogininfo.txt");
    while(in.eof()==0)
    {
        in>>personType;
        in>>personNickName;
        in>>personID;
        in>>personPassword;

        if((id==personID)&&(password==personPassword))
        {
            break;
        }
    }

    cout<<personType;
    if(personType=="1")
    {
        home_admin();
    }
    else if(personType=="2")
    {
        home_teacher(personID);
    }
    else if(personType=="3")
    {
        home_student();
    }
    else
    {
        login();
    }

    //person p1=person("rahim","12","asd",12);
}
