//Author: Neha Vardhaman
//Date: March 27, 2020

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void ch13();

void findSubStrings(); 
int findSubStrings(char* pstr, const char* substr, char* location[]);

void findLastSubString();
const char* findLastSubString(const char* str, char const* substr);

void strrem(char str[], char str2[], char substr[]);
void doFindLastSubString(int argc, char* argv[]);

void replaceStrs();
char* replaceStrs(char*, const char*, const char*);

void fmoomoo2(void);

extern char ch13FuncsNames[][30];

extern void (*ch13Funcs[])();