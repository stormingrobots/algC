//Author: Neha Vardhaman
//Date: March 27, 2020

#include <common.h>
#include <ch12.h>

void ch12() {
	printf("Do ch12 selection... \n");
	return;
}

//programming project 1
void reverse() {
	char a[10001];
	char *p;

	printf("Enter a a: ");
	for (p = a; (*p = getchar()) != '\n' && p < a + 10000; p++) {
	}

	printf("In reverse order: ");
	for (p--; p >= a; p--) {
		printf("%c", *p);
	}
}

//programming project 2
void palindrome() {
	bool isPalindrome = true;
	char a[10000], *p, ch, *q;

	printf("Enter a message: ");
	for (p = a; (ch = getchar()) != '\n';) {
		ch = tolower(ch);
		if (ch >= 'a' && ch <= 'z') {
			*p = ch;
			p++;
		}
	}

	uInt nletters = (uInt)(p - a);
	for (q = a, p--; q <= a + (nletters / 2); p--, q++) {
		if (*p != *q) {
			isPalindrome = false;
			printf("Not a palindrome");
			break;
		}
	}

	if (isPalindrome == true) {
		printf("Palindrome");
	}
}
