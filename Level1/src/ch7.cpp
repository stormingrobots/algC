// These are the ones level I students should eventually have by 
// the end of Level I
// Author: Storming Robots
// Date:  March 23rd, 2020
// 
#include "ch7.h"

void scrabble()
{
	char score[] = {
		//A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q,  R, S, T, U, V, W, X, Y, Z
		  1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
	};
	int total = 0, ch;

	printf("Enter your word:  ");
	while ((ch = getchar()) != '\n') {
		if (!isalpha(ch)) {
			printf("%c is not an alphabet!\n", ch);
			break;
		}
			ch = tolower(ch);
		total += score[ch - 'a']; 
	}
	return;
}

void avgWordLength()
{
	char ch = 0;
	char lastCh = ' ';
	int wordsCt = 0, letters = 0;
	showMe;
	do {
		if (ch != ' ' && lastCh == ' ')
		{	// it is  new word
			++wordsCt;
		}
		lastCh = ch;
		++letters;

	} while ((ch = getchar()) != '\n');

	printf("average = %.1f\n", ((double)letters / wordsCt));
}

// do note that this assume getNum( ) will return a valid number

void calc()
{
	double num, total = 0;
	char ch;
	showMe;
	total = getNum();  
	while ((ch = getchar()) != '\n')
	{
		num = getNum(); 
		if (errno) {
			printf("%s!\n", strerror(errno));
			return;
		}
		while ((ch = getchar()) == ' '); // skip spaces
		ch = getchar(); 
		switch (ch)
		{
		case '*':
			total *= num;
			break;
		case '/':
			total /= num;
			break;
		case '+':
			total += num;
			break;
		case '-':
			total -= num;
			break;
		default:
			printf("ERROR");
			return;
		}
	}
	printf("%lf", total);
	return;
}




void convertPhone()
{
	showMe;
	char ch;
	const int len = 15;
	char num[len]{ 0 };
	int i = 0;

	showMe;

	printf("Enter phone number (with letters): ");
	while ((ch = getchar()) != '\n') {
		if (isalpha(ch))
		{
			ch = toupper(ch);
			if ((ch == 'Q') || (ch == 'Z')) continue;
			if (ch < 'R')
				printf("%d", (ch - 'A') / 3 + 2);
			else
				printf("%d", (ch - 'B') / 3 + 2);
		}
		else
			printf("%c", ch);
	}
}

void firstNLname()
{
	//Last viewed date:3/7/20
	//Status: none
	showMe;
	char first, ch;

	printf("\nPlease Enter Your Name: ");

	while ((first = getchar()) == ' ');

	while (getchar() != ' ');

	printf("You entered the name: ");
	while ((ch = getchar()) != '\n')
	{
		if (ch == ' ') continue;
		printf("%c", ch);
	}
	printf(", %c.", first);
}


int ch7Main() {
	printf("Do selection for ch7.\n-----------\n");
	return 0;
}
