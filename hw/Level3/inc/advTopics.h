#pragma once

#include <common.h>
#include <conio.h>

//#include <varargs.h>
#include<stdarg.h>

void print(const char* msg, ...);
void digitalDisplay(int num);

void digitalDisplayTime(char* tm);
void displayClock();
void sleep(float);
void create2D_test();

int getNext(const char* list, char sym, bool* done);