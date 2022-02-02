#pragma once

// for the students, tell them to add their common.h to
// their current folder, and use "common.h"

#include <common.h> 

void  ch7Main();

void scrabble();
void avgWordLength();
void calc();
void convertPhone();
void firstNname(); 

extern char ch7FuncsNames[][20];
extern void (*ch7Funcs[])();