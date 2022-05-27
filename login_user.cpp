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
