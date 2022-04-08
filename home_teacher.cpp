#include "header.h"
using namespace std;

void home_teacher(string teacher_id)
{
    string rept_teacher_to_admin(".//reports//teacher_to_admin.txt");
    string report;
    int choice;

    string window_option[10];
    basic_window();
    window_option[0]="Set Continious Evolution Mark";
    window_option[1]="Veiw Students Info";
    window_option[2]="Make a report";

    choice = option_input_on_window(window_option,3,1);

    if(choice==3)
    {
        system("cls");
        gotoxy(5,3);
        cout<<"Teacher Home :: Make a Report";

        fstream file;
        file.open(rept_teacher_to_admin,std::ios_base::app);
        if(file.is_open())
        {
            report = taking_report();
            file<<report<<endl;
            file.close();

            confirmation_popup("Report/Query sent succcesfully");
        }
    }
    if(choice==1)
    {
        if(two_confirmation_popup("How do you want to update the continious evolution mark?","Batchwise","For a particular student"))
        {
            for(auto a: list_of_files())
        }
        
        vector<int> choice1=ret_selected_course_num(ret_selected_course_of_teacher(teacher_id));
        student s;
        s.upadate_continious_evolution_mark(func_makeFilename("12","1201"),2.3,choice1[0],choice1[1]);
    }
}
