// test2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
using namespace vex;

int main()
{
	const int r = 3, c = 5;
	int x[r][c] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15} };
	int** ip;  // not good

	char sc[r][c] = { "1aa", "2bbb", "3ccc" };
	char** cp = (char**)sc;  // not good

	const char *ss[4] = { "1234567890", "12345", "xyz"};
	char** sp = (char**)ss;

	int A[r][c], * ptr1, ** ptr2;
	ptr2 = &ptr1;
	ptr1 = (int*)A;   // the value of n info is lost

	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
