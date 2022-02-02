//Author: Neha Vardhaman
//Date: March 27, 2020

#include "ch11.h"

//exercise 4
void swap(int *p, int *q) {
	int x, *temp = &x;
	*temp = *p;
	*p = *q;
	*q = *temp;
}

//exercise 5
void split_time(long total_sec, int *hr, int *min, int *sec) {
	*sec = total_sec % 60;
	*min = (total_sec / 60) % 60;
	*hr = total_sec / 60 / 60;
}

//exercise 6
void find_two_largest(int a[], int n, int *largest, int *second_largest) {
	*largest = a[0];
	*second_largest = a[1];
	for (int i = 1; i < n; i++) {
		if (a[i] > *largest) {
			*second_largest = *largest;
			*largest = a[i];
		} else if (a[i] > *second_largest) {
			*second_largest = a[i];
		}
	}
}

//exercise 7
void split_date(int day_of_year, int year, int *month, int *day) {
	*month = day_of_year / 31;
	*day = day_of_year - (*month * 31);
}

//exercise 8
int *find_largest(int a[], int n) {
	int *plargest = &a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > *plargest) {
			plargest = &a[i];
		}
	}
	return plargest;
}

int misc_ch11() {
	char str[100] = "abc";
	const char* x = "abc";
	char* x2 = str;
	
	printf(" %c\n", *(++x));
	//printf(" %s\n", *(++str));  // illegal
	printf(" %c\n", *(++x2));

	return 0;
}