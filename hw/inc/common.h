#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <conio.h>

#define Min(a, b)  (a > b ? a : b)
#define Max(a, b)  (a > b ? a : b)

// struct myPOINT { double x, y; };  alredy in windef.h?!
#define showMe  showFileStats()

double getNum();
double getNumStrong();
int gcdR(int a, int b);
int gcd(int a, int b);

void showFileStats(char* exe=NULL);
void prt2DColor(int* x, int r, int c);
void prt2Dv(int* x, int r, int c);

int mainTemplate(void  (*funcs[])(), char (*funcsNames)[20], int maxSel);