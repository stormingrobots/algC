// digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "time.h"
#include "memory.h"
#include "stdlib.h"

char digits[10][7] = {
	{ 1,1,0,1,1,1,1 },{ 0,0,0,1,0,0,1 },{ 1,0,1,1,1,1,0 },
	{ 1,0,1,1,0,1,1 },{ 0,1,1,1,0,0,1 },{ 1,1,1,0,0,1,1 },
	{ 1,1,1,0,1,1,1 },{ 1,0,0,1,0,0,1 },{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,0,0,1 }
};
char led[] = "_|_||_|";

void display( char x[] )
{
	int r, c, i, j, n = 0;
	char ch;

	n = strlen(x);
	for (r = 0; r< 3; r++)
	{
		printf("\n");
		for (i = 0; i < n; i++)  // digit
		{
			j = x[i] - '0';
			if (x[i] == ':')
			{
				(r == 1 ? printf(":") : printf(" "));
				continue;
			}
				
			if (r == 0)
			{
				(digits[j][0] == 1 ? printf(" %c ", led[0]) : printf("   "));
				continue;
			}
			// 2nd & 3rd row
			for (c = (r - 1) * 3 + 1; c <= r * 3; c++)
				(digits[j][c] == 1 ? printf("%c", led[c]) : printf(" "));
		}
	}
	printf("\n");
}


void displayNumbers()
{
	int r, c, i, j, n = 0;
	char ch;
	char x[20];

	while ((ch = getchar()) != '\n')
	{
		x[n++] = ch;
		if (n >= sizeof(x))
			break;
	}

	for (r = 0; r< 3; r++)
	{
		printf("\n");
		for (i = 0; i < n; i++)  // digit
		{
			j = x[i] - '0';
			if (r == 0)
			{
				(digits[j][0] == 1 ? printf(" %c ", led[0]) : printf("   "));
				continue;
			}
			// 2nd & 3rd row
			for (c = (r - 1) * 3 + 1; c <= r * 3; c++)
				(digits[j][c] == 1 ? printf("%c", led[c]) : printf(" "));
		}
	}
	printf("\n");
}


int main()
{
	struct tm *me;
	time_t now;
	char stm[20];

	while (true)
	{
		time(&now);
		me = localtime(&now);
		sprintf(stm, "%2d:%02d:%02d", me->tm_hour, me->tm_min, me->tm_sec);
		display(stm);
		system("sleep 1 & cls");

	}
	return 0;
}

