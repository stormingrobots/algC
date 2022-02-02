#pragma once

// Author: Storming Robots
// Date:  March 23rd, 2020
// 


typedef unsigned char uByte;

// // is it 0b 10000000 or 00000001
struct S {
	uByte filler : 7;
	uByte	flag : 1;
};


struct Color {
	int r = 0, g = 0, b = 0;
};

struct SColor {
	Color it;
	char name[10]{ 0 };
};


struct Fld {
	uByte n : 1;
	uByte e : 1;
	uByte s : 1;
	uByte w : 1;
	uByte filler : 4;
};

union {
	unsigned val = 0;
	struct Fld {
		uByte n : 1;
		uByte e : 1;
		uByte s : 1;
		uByte w : 1;
		uByte v1 : 2;
		uByte v2 : 2;
	} u;
} ubitFld;


int compInt(const void*, const void*);
int compString(const void*, const void*);
int compDate(const void*, const void*);

extern int(*comp[3])(const void*, const void*);

enum enCompareType { isInt, isString, isDate };

int csv(int, const char*[]);