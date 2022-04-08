#include "header.h"

bool string_binary_search(string filename, int line, string search_thing)
{

}

int binarySearch(string arr[], string key, int size)
{

}

vector<string> list_of_files(string folder)
{
    vector<string> names;
    string search_path = folder + "/*.*";
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
    if(hFind != INVALID_HANDLE_VALUE) {
        do {

            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.push_back(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
    return names;
}

bool check_file_if_exits(string filename, string folderName)
{
    vector<string> filenames = list_of_files(folderName);

    for(auto E : filenames)
    {
        if(E==filename)
            return true;
    }

    return false;
}

vector<string> ret_selected_course_of_teacher(string teacher_id)
{
    string taken_teacher_id,temp_string;
    fstream coursefile;
    vector<string> coursesFromFile;

    coursefile.open(".//academic//teacher_assign_to_course.txt");

    while(coursefile.eof()==0)
    {
        getline(coursefile,taken_teacher_id);
        if(taken_teacher_id==teacher_id)
        {
            while((coursefile.peek()!='\n')&&(coursefile>>temp_string))
            coursesFromFile.push_back(temp_string);
        }
    }
    return coursesFromFile;
}

int ret_selected_course_num(vector<string> courses)
{
    string temp, option[10];
    int i=0,size = courses.size();
    for(auto t:courses)
    {
        option[i]="Semister "+to_string(t[0])+"Course "+to_string(t[2]);        //ektu bug to string e
        i++;
    }
    int choice = option_input_on_window(option,i,2);

}

string func_makeFilename(string batch_serial, string student_id)
{
    string new_student_id,makefilename;

    if(convert_stringToNumber(student_id)<10)
        new_student_id=batch_serial+"//"+batch_serial+"0"+student_id+".dat";
    else
        new_student_id=batch_serial+"//"+batch_serial+student_id+".dat";

    makefilename=".//studentData//batch"+new_student_id;

    return makefilename;
}
