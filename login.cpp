#include "header.h"
using namespace std;

void login()
{
    string id, password;
    string personType, personNickName, personID, personPassword;


    gotoxy(10,5);
    cout<<"Enter Your User ID: "<<endl;

    gotoxy(10,6);
    cout<<"Enter Your Password: "<<endl;

    gotoxy(33,5);
    cin>>id;

    gotoxy(33,6);
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
    //person p1=person("rahim","12","asd",12);

}
