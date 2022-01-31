
#include "ch8.h"

void showAllDigitsCount()
{
	showMe;
	int digits[10] = { 0 };
	int i = 0;
	char ch;

	while ((ch = getchar()) != '\n')
		digits[ch - '0'] += 1;

	printf("\n\n===========Repeated Digits are:\n");

	for (i = 0; i < 10; ++i)
	{
		if (digits[i] > 1)
			printf("%4d", i);
	}
}


void show0to9Frequency()
{
	showMe;
	int digits[10] = { 0 };
	int i = 0;
	char ch;

	while ((ch = getchar()) != '\n')
		digits[ch - '0'] += 1;

	printf("\n\n===========Frequency of repeated Digits:\n");

	for (int i = 0; i < 10; ++i)
		printf("%3d", i);
	printf("\n");
	for (int i = 0; i < 10; ++i) {
		printf("%3d", digits[i]);
	}

}

void sentenceReverse() {
	showMe;
	const int MaxLen = 80;
	int i = 0, wdCt = 0;
	char lastCh = ' ', ch;
	char pos[MaxLen] = { 0 };
	char sentence[MaxLen] = { 0 };

	printf("Enter a sentence: ");

	while ((ch = getchar()) == ' ') sentence[i++] = ch; // leading spaces

	do {
		if (ch != ' ' && lastCh == ' ') {
			pos[wdCt++] = i;  // it is  new word
		}
		sentence[i++] = ch;
		lastCh = ch;
	} while (!isPunct((ch = getchar())) && i < MaxLen);

	char punch = ch;
	sentence[i++] = ch;
	sentence[i] = 0;

	printf("\nReversal of sentence:");

	while (--wdCt >= 0) {
		int idx = pos[wdCt];
		printf(" ");
		do {
			printf("%c", sentence[idx++]);
		} while (sentence[idx] != ' ' && !isPunct(sentence[idx]));
	}
	printf("%c\n", punch);
	
}


bool isAnagram()
{
	showMe;
	int letters[26] = { 0 };
	char ch;

	printf("Enter first word: ");

	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			ch = tolower(ch);
			letters[ch - 'a'] += 1;
		}
	}
	printf("\nEnter second word: ");

	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			ch = tolower(ch);
			letters[ch - 'a'] -= 1;
		}
	}

	// use ch as the check : 
	// ch == 0 : anagram
	// ch != 0 : not anagram
	for (int i = 0, ch = 0; i < 26 && !ch; ++i) {
		ch = letters[i];
	}

	//or : 
	int i = 0;
	while (i < 26) {
		if (letters[i++] != 0)
			return false;
	}
	return true;
}


//-------------------------------------
#define shouldContinue  ( tolower(getchar()) == 'y' && getchar())

//--------------------------

#define nextLetter(c)  c++

void walk()
{
	showMe;
	const char Up = 0, Right = 1, Down = 2, Left = 3;
	const int maxN = 10;
	char walk[maxN][maxN], sym = '.';

	srand((unsigned)(time(NULL)));

	do {
		int r = 0, c = 0;
		int move;
		char letter = 'A';
		int nfails = 0;
		// reset-------------
		for (int i = 0; i < maxN; ++i) {
			for (int j = 0; j < maxN; ++j)
				walk[i][j] = sym;
		}
		walk[0][0] = letter++;

		// perform a round-------------------
		while (letter <= 'Z' && nfails < 4) {

			// get a new move only if the last move is placed
			if (nfails == 0)
				move = rand() % 4;

			switch (move) {
			case Up:
				if (r > 0 && walk[r - 1][c] == sym) {
					walk[--r][c] = nextLetter(letter);
					nfails = 0;
					continue;
				}
				++nfails;

			case Right:
				if (c < maxN - 1 && walk[r][c + 1] == sym) {
					walk[r][++c] = nextLetter(letter);
					nfails = 0;
					continue;
				}
				++nfails;

			case Down:
				if (r < maxN - 1 && walk[r + 1][c] == sym) {
					walk[++r][c] = nextLetter(letter);
					nfails = 0;
					continue;
				}
				++nfails;
			case Left:
				if (c > 0 && walk[r][c - 1] == sym) {
					walk[r][--c] = nextLetter(letter);
					nfails = 0;
					continue;
				}
				++nfails;
				move = 0;
			}
		}
		// ending a round; print out the board -------------------
		for (int i = 0; i < maxN; i++) {
			for (int j = 0; j < maxN; j++)
				printf("%2c", walk[i][j]);
			printf("\n");
		}
		// show where you are stucked if you are 
		if (letter <= 'Z')
			printf("Stuck on %c!!!!! \n\n", letter - 1);

		printf("Wish to continue? Y/N:  ");

	} while (tolower(getchar()) == 'y' && getchar());
}




// get input from getNum
void sumRows_Cols1() {

	int arr[5][5]; //stores all numbs
	int row, col; //row and column
	float rows[5] = { 0 }; //rowtotals
	float cols[5] = { 0 }; //coltotals
	for (row = 0; row < 5; row++)
	{
		printf("Enter row %d: ", row + 1);
		for (col = 0; col < 5; col++)
		{
			arr[row][col] = (int)getNum(); // inputs numb into each index
			rows[row] = arr[row][col] + rows[row]; //for adding rows
			cols[col] = arr[row][col] + cols[col]; //for adding col
		}
		printf("\n");
	}
	printf("Row totals: ");
	for (row = 0; row < 5; row++)//prints row
	{
		printf("%f, ", rows[row]);
	}
	printf("\nColumn Totals: ");
	for (col = 0; col < 5; col++) //prints col
	{
		printf("%f, ", cols[col]);
	}
}


void sumRows_Cols2() {
	showMe;
	const int nRows = 5, nCols = 5;
	int nums[nRows][nCols]{ 0 };
	int rowS[nRows] = { 0 }, colS[nCols] = { 0 };

	//fill the set with random datas
	for (int r = 0; r < nRows; ++r) {
		for (int c = 0; c < nCols; ++c) {
			nums[r][c] = rand() % 10;
		}
	}
	//Get all the numbers
	for (int r = 0; r < nRows; ++r) {
		//printf("Enter all row %d: ",r);
		for (int c = 0; c < nCols; ++c) {
			//nums[r][c] = (int)getNum();
			rowS[r] += nums[r][c];
			colS[c] += nums[r][c];
		}

	}

	printf("\n\nRow Totals: ");
	for (int r = 0; r < nRows; ++r)
		printf("%d ", rowS[r]);

	printf("\n\nCol Totals: ");
	for (int c = 0; c < nCols; ++c)
		printf("%d ", colS[c]);

}


// external to the book
// supplemental exercise
// sum the right diagonal and left diagonal
// remember : students have yet learnt pointers
// get them used to use sizeof
void sumdiagonals() {
	const int dim = 5;
	int grids[dim][dim];
	int right = 0, left = 0;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			grids[i][j] = i * j;
			printf("%3d ", grids[i][j]);
		}

		printf("\n");
	}
	//tell them this cannot be done
	//const int dim = sizeof(grids) / sizeof(grids[0]);

	for (int r = 0, c = dim - 1; r < dim; r++, c--) {
		left += grids[r][r];
		right += grids[r][c];
	}
}


// digital display: Defines the entry point for the console application.
//
void digitalDisplay(int num)
{
	char x[30];

	char digits[10][7] = {
	{ 1,1,0,1,1,1,1 },{ 0,0,0,1,0,0,1 },{ 1,0,1,1,1,1,0 },
	{ 1,0,1,1,0,1,1 },{ 0,1,1,1,0,0,1 },{ 1,1,1,0,0,1,1 },
	{ 1,1,1,0,1,1,1 },{ 1,0,0,1,0,0,1 },{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,0,0,1 }
	};
	char led[] = "_|_||_|";


	int r, c, i, j, n = 0;

	// split the number into an array
	int numDigits = 0;
	for (numDigits = 0; num > 0; numDigits++) {
		x[numDigits] = num % 10;
		num /= 10;
	}
	// reverse it 
	for (int i = 0; i < numDigits / 2; i++) {
		char tmp = x[numDigits - i];
		x[numDigits - 1] = x[i];
		x[i] = x[numDigits - 1];
	}

	for (r = 0; r < 3; r++)
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



int ch8Main() {
	printf("Do selection for ch8.\n-----------\n");
	return 0;
}
