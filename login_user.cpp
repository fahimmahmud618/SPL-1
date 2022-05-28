#include "header.h"
#include "b_plus_tree.h"
using namespace std;

struct Hash {
    const int p = 31, m = 1e9 + 7;
    int hash_value;
    Hash(const string& s)
    {
        int previous_hash_value = 0;
        long p_pow = 1;
        const int n = s.length();
        for (int i = 0; i < n; ++i)
        {
                previous_hash_value = (previous_hash_value + (s[i] - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;
        }
        hash_value = previous_hash_value;
    }

    bool operator==(const Hash& other) {
        return (hash_value == other.hash_value);
    }
};

void user_login()
{
    int x;
    cout<<"Witch type of user you are?"<<endl;
    string window_option[3];
    window_option[0]="Admin";
    window_option[1]="Teacher";
    window_option[2]="Student";
    int choice = option_input_on_window(window_option,3,1);

    BPTree node;
    int temp_hash_value;
    string personID, password, personType, treeInput;

    ebcdic_decrypt("loginFile.txt");
	ifstream in("loginFile.txt");
	in>>personID;
    while(in.eof()==0)
    {
        in>>personID;
        in>>password;
        in>>personType;

        treeInput = personID+password+personType;
        Hash h(treeInput);
        temp_hash_value = h.hash_value;
        node.insert(temp_hash_value);

       // cout<<treeInput<<" "<<temp_hash_value<<endl;
    }

    ebcdic_encrypt("loginFile.txt");
    string id,given_password;

	//basic_window();
    gotoxy(15,10);
    cout<<"Enter Your User ID: "<<endl;

    gotoxy(15,11);
    cout<<"Enter Your Password: "<<endl;

    gotoxy(38,10);
    cin>>id;

    try {
        gotoxy(38,11);
        cin>>given_password;
        if (if_contains_other_char(given_password))
          {
             treeInput = id+given_password+to_string(choice);

                //cout<<endl<<treeInput<<" "<<temp_hash_value<<endl;
                Hash h2(treeInput);
                temp_hash_value = h2.hash_value;
                if(node.search(temp_hash_value))
                    {
                        if(choice==1)
                            home_admin();
                        else if(choice==2)
                            home_teacher(id);
                        else
                            home_student(id);
                    }
                else
                    confirmation_popup("Wrong ID or password, Check Again!");

          }
        else
        {
            throw x;
        }
   }
   catch (int x ) {
      cout << "Exception Caught \n";

      Sleep(2000);
      system("cls");
      user_login();
   }
}

bool change_password(string id, string type)
{
    string personID,personType,old_pass,new_password,personPassword,login_file = "loginFile.txt";
    ebcdic_decrypt(login_file);
    ifstream in(login_file);
    ofstream output;
    output.open("temp",ios::binary);
    bool flag = false;

    basic_window();
    gotoxy(15,10);
    cout<<"Enter Your Old password: "<<endl;
    gotoxy(45,10);
    cin>>old_pass;

    in>>personID;
    output<<"N"<<endl;
    while(in.eof()==0)
    {
        in>>personID;
        in>>personPassword;
        in>>personType;

        if((id==personID)&&(type==personType))
        {
            cout<<"found";
            gotoxy(15,11);
            cout<<"Enter Your new Password: "<<endl;
            gotoxy(45,11);
            cin>>new_password;
            personPassword = new_password;
            flag = true;

        }

            output<<personID+" "+personPassword+" "+personType<<endl;
    }
    char filename[] = "loginFile.txt";
    char ch,oldname[]="temp" ;
    char* newname= &login_file[0];
    in.close();
    output.close();
    cout<<remove(filename);
    rename(oldname,newname);

   return flag;
}

