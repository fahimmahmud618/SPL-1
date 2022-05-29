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
#include <climits>
#include <direct.h>
#include <sstream>
#include <ftw.h>
#include "all_class.h"

using namespace std;
bool if_contains_other_char(string given_string);
bool change_password(string id, string type);
void user_login();
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
        void make_marksheet();
        void take_attendance(vector<string> rolls, string batch_serial, int course_num, int semister_num);
        void set_assignment(string batch_serial);

    void home_admin_control_reports();

void home_teacher(string teacher_id);
void home_student(string personID);
    string taking_report();
string retfileNameFromID(string id);

//ebcdic
string convert_to_four_bit(string x);
string dec_to_binary_convert(int n);
int binary_to_decimal(int n);
char ret_char_from_code(string zone_code, string digit_code);
string ret_digit_bit(char x);
string ret_zone_bit(char x);
void ebcdic_encrypt(string taken_file);
void ebcdic_decrypt(string taken_file);

void attendance_counter(string fileName);
//void LIS_NAIVE(int n, int x[N], int &maxlen);
#endif // HEADER_H_INCLUDED
