
// for Struct/ union packet work
// 
// Author: Storming Robots
// Date:  March 23rd, 2020
// 
#include <cstddef>
#include <common.h>
#include "struct_2.h"



int(*comp[3])(const void*, const void*) = { compInt, compString, compDate };

struct Fld u = { 4 };  // pre set e

void checkOutBitsOrder() {
	printf(" r at : %zu\n g at %zu\n b at %zu\n name at %zu\n", 
		offsetof(SColor, it.r), offsetof(SColor, it.g), 
		offsetof(SColor, it.b), offsetof(SColor, name));

	SColor  tst = { { 255, 0, 0 }, "testing" };
	printf(" r at : %p\n g at %p\n b at %p\n name at %p\n",
		&(tst.it.r), &(tst.it.g), &(tst.it.b), tst.name);
	printf(" r at : %d\n g at %d\n b at %d\n name at %s\n",
		(tst.it.r), (tst.it.g), (tst.it.b), tst.name);
	ubitFld.u.n = 1;
	ubitFld.u.v2 = 1;
	// you will see 0x01
	printf(" bitfield = 0x%2x \n", ubitFld.val);

}

int compInt(const void* p, const void* q) {
	int* n1 = (int*)p;
	int* n2 = (int*)q;

	return (*n1- *n2);
}

int compString(const void* p, const void* q) {
	char* str1 = (char*)p;
	char* str2 = (char*)q;

	return (strcmp(str1, str2));
}

int compDate(const void* p, const void* q) {
	char* str1 = (char*)p;
	char* str2 = (char*)q;

	// leave this to you.. 

	return (0);
}

// check out the bits order
void testBits() {
	S s;
	memset(&s, 0, sizeof(s));
	s.flag = 1;

	int x = 1, y = 0;

	printf("%x\n", s.flag);
	uByte b; memcpy(&b, &s, 8);
}