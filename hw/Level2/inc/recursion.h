#pragma once

#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <common.h>
typedef unsigned long uLong;

void recursion(); 
void reverseString(char*);
void doRecursion();
void showBinary(int);
uLong fib(int);
int findMin(int*, int);
void doFindMin();
void doFib();
void doBraces();
void doPal();
void doBinSearch();
void doBinarydisplay();

int balance(const char*);
int balance(char*, char**);
int iCompare(const void*, const void*);
bool isPalindrome(char*, size_t);
void* binSearch(void*, int, int, void*, int (*)(const void*, const void*));

