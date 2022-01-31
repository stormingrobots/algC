//============================================================================
// Name        : recursion.cpp
// Author      : Storming Robots
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <recursion.h>

void recursion() {
	printf("Do recursion selection... \n");
	return;
}

// do not expose this one: 
void reverseString(char*, char*);

int findmin(int *a, int n) {
	if (n == 0) return *a;
	int m = findmin(a + 1, n - 1);
	if (m < *a)
		return m;
	return *a;
}
//or 
int findmin2(int *a, int n) {
	if (n == 0) return *a;
	int m = findmin(a, n - 1);
	if (m < a[n])
		return m;
	return a[n];
}

//wrapper function
void reverseString(char* str) {

	reverseString(str,  str+ strlen(str)-1);
}

void reverseString(char*beg, char*end)
{
	if (beg >= end)	return;
	char c = *end; 
	*end = *beg;
	*beg = c;
	reverseString(beg+1, end-1);
}


// using Dynamic programming top-down method
//
uLong  fib(int n)
{
	static uLong *lookup = NULL;

	if (lookup==NULL) {
		lookup = (uLong *)malloc ( ((size_t)n+1)*sizeof(*lookup) );
		if (lookup == NULL)
			return 0;
		memset(lookup, 0, sizeof(int)* ((size_t)n + 1));
	}

	if (lookup[n])
		return lookup[n];

	if (n <=2) lookup[n] = 1;

	lookup[n] = fib(n-1)+fib(n-2);
	return (lookup[n]);
}


void showBinary(int n, int len) {

	if (n == 0)
		return;
	showBinary(n / 2, len + 1);
	printf("%d", n % 2);
	if (len % 4 == 0) {
		printf(" ");
	}
}

//wrapper
void showBinary(int n) {
	int len = 0;
	showBinary(n, len);
}

//-------------  the driver functions ------

// should NEVER do this
int fibBad(int n)
{
	if (n<=2)  return 1;
	return fibBad(n-1)+fibBad(n-2);
}

// 	(1.618034^n - (-0.618034^n) ) / sqrt(5)
//          6    8      10      12
//1 1 2 3 5 8 13 21 34  55  89  144

void doRecursion() {
	int num=0;
	cout<< "Enter a number to tabulate fibonacci : ";
	cin >> num;
	cout << fib(num) << endl; //
	return;
}

void doBinarydisplay() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		showBinary(n);
		printf("\n     %d = 0x%x\n------------\n", n, n);
	}

}