// These are the ones level I students should eventually have by 
// the end of Level I
// Author: Storming Robots
// Date:  March 23rd, 2020
// 
#include <ch7.h>

// by Storming Robots
// Do note:  This pointer to function methods should not be introduced 
//           until level 3. 

void (*ch7Funcs[])() = { scrabble, avgWordLength, calc, convertPhone, firstNname };
char ch7FuncsNames[][20] = {
	 "scrabble", "avgWordLength", "calc", "convertPhone", "firstNname" };

void  ch7Main() {
	int sel = 0;
	int maxSel = sizeof(ch7Funcs) / sizeof(ch7Funcs[0]);
	do {
		printf("=============================\nWhich one to run?\n");
		for (int i = 0; i < maxSel; i++) {
			printf("\t%d for %s\n", i + 1, ch7FuncsNames[i]);
		}
		printf("\t0 to terminate!\n");
		printf("-------------------------\n");
		printf("Select: ");

		sel = (int)getNum();
		if (sel == 0) break;
		if (sel < 0 || sel > maxSel) {
			printf("Invalid Selection. Valid [ 1 to %d ] !\n", maxSel);
			continue;
		}

		ch7Funcs[--sel]();
	} while (1);

}



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

void  firstNname() {
	return;
}