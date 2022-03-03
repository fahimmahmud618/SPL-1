#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <direct.h>
#include "person.h"
#include "student.h"
#include "semister_course.h"

using namespace std;

void login();
void gotoxy(int x, int y);
void color(int color);

void home_admin();
    void add_student();


#endif // HEADER_H_INCLUDED
