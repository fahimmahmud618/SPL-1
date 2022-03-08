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
#include "student.h"
#include "semester_course.h"

using namespace std;

void login();
void gotoxy(int x, int y);
void color(int color);

//function_window
    void basic_window();
    int option_input_on_window(string *option_array, int size);

void home_admin();
    void home_admin_control_teacher();
    void home_admin_control_student();
        void add_student();
        void modify_student(int batch_serial, int student_id);
        void delete_student();
        void view_student_info();
    void home_admin_control_reports();

void home_teacher();
void home_student();


#endif // HEADER_H_INCLUDED
