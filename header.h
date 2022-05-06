#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <direct.h>
#include <ftw.h>
#include "person.h"
#include "all_class.h"
#include "student.h"
#include "academic.h"
#include "semester_course.h"

using namespace std;

void login();
void color(int color);

//function_window
    void basic_window();
    int option_input_on_window(string *option_array, int size, int side);
    bool two_confirmation_popup(string title, string option1, string option2);
    void confirmation_popup(string title);
    vector<string> taking_list_input_on_window(string *option_array, int size, int side);

//function_file
    bool check_file_if_exits(string filename, string folderName);
    vector<string> list_of_files(string folder);
    vector<string> ret_selected_course_of_teacher(string teacher_id);
    vector<int> ret_selected_course_num(vector<string> courses);
    string func_makeFilename(string batch_serial, string student_id);
    string ret_batchSerial(string semister_num);

//function_basic
    void gotoxy(int x, int y);
    int calc_string_len(string input);
    bool check_number_or_not(string input);
    bool encrypt(string taken_file);
    bool decrypt(string taken_file);
    int convert_stringToNumber(string s);


void home_admin();
    void home_admin_control_teacher();
        void edit_teacher_basic_info(string teacher_id);
        void view_teacher_info_func(string teacher_id);
    void home_admin_control_student();
        void add_student();
        void modify_student(int batch_serial, int student_id);
        void delete_student();
        void view_student_info();
        void register_student(string student_file, string student_id, int semister);
        void update_continious_evolution_mark(string person_id);
    void home_admin_control_reports();

void home_teacher(string teacher_id);
void home_student();
    string taking_report();




#endif // HEADER_H_INCLUDED
