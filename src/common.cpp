
#pragma once
#pragma warning(disable:4996)	

#include <common.h>   

// will get rid of leading spaces
// will not handle training spaces. 
// e.g.  spsp339spsp14
// // where sp == ' '
// when the function returns, the input queue will still have spsp14 in it. 

/*-----------------
"  123"  returns 123
"123"  returns 123
"123.4"  returns 123.4
"123.99999" returns 123.99999

rules:
- should retain all the precisio that user entered
- should not affect any chars trailing the number,
   e.g. .123.+
   return 0.123, but '+' should remain in the stdin queue
   e.g. 123+
   return 123, but '+' should remain in the stdin queue
   e.g. 123.+
   return 123, but '+' should remain in the stdin queue

123.10+9 returns 123.99999

*/

double getNum()
{
	char ch;
	double  real = 0, decPl = 0;
	double neg = 1;

	// get rid of all leading spaces and endl

	while ((ch = getchar()) == ' ' || ch == '\n');

	if (ch == '-')
		neg = -1;
	else
		ungetc(ch, stdin);

	while (1)
	{
		// error checking:
		if (!(isdigit(ch = getchar()) || ch == '.')) {
			break;
		}

		if (ch == '.') {
			if (decPl > 0)
				break;  // 2nd '.' 
			decPl = 1;
			continue;
		}

		if (decPl != 0) decPl *= 10;
		
		real = (10 * real) + ch - '0';
	}

	// do retain higher precision, either use double or do the following trick
	// e.g. x = x * 1/1000 , not x  = x / 1000

	if (decPl > 0)
		real *= 1 / decPl * neg;

	ungetc(ch, stdin);

	return real;

}

// but the following version is probably easier to understand...
// also: 
//     it requires user to hit enter key before  it allows 
//     you to read each character. This is due to how the OS deal with buffer.
//This version allows you to get character from 
//     stdin without waiting for user to hit enter. 

double getNumStrong()
{
	char ch;
	double real = 0, decPl = 0;

#ifdef __linux__
	system("stty raw");
#endif
	while ((ch = getch()) == ' ');
	if (isdigit(ch)) {
		do {
			real = (10 * real) + ch - '0';
		}             while (isdigit(ch = getch()));
	}


	if (ch != '.') {
#ifdef __linux__
		system("stty cooked");
#endif
		return real;
	}

	double pl = 1;
	while (isdigit(ch = getch())) {
		decPl = (10 * decPl) + ch - '0';
		pl = pl * 10;
	}
	// do retain higher precision, either use double or do the following trick
	// e.g. x = x * 1/1000 , not x  = x / 1000
	decPl *= 10;
	decPl *= 1 / (pl * 10);

#ifdef __linux__
	system("stty cooked");
#endif
	ungetc(ch, stdin);

	return real + decPl;


}


int gcdR(int a, int b) {

	if (b == 0) {
		showMe; return a;
	}
	return gcdR(b, a % b);
}


int gcd(int a, int b) {
	int r;
	showMe;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}



void showFileStats(char* exe) {

	struct stat statBuf;
	int m = stat(__FILE__, &statBuf);
	printf("%s: %d\n", __FILE__, statBuf.st_size);
	m = stat(exe, &statBuf);
	printf("%s: %d\n", exe, statBuf.st_size);
}


void prt2DColor(int* x, int r, int c) {

	for (int i = 0; i < r; i++) {
		printf("Raw %d: ", i);
		for (int j = 0; j < c; j++) {
			int* p = x + (size_t)i * (size_t) j;
			char color[20];
			sprintf(color, "\033[01;%dm ", i * j + 31);
			printf("%s (\"%s\") %d", color, &color[5], *p);
		}
		printf("\n");
	}
}


void prt2Dv(int* x, int r, int c) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%04d", *(x + (size_t)(i * j)));
		}
	}
}

