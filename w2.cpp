#include <iostream>
using namespace std;
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define dot '.'


//const char Up = 0, Right = 1, Down = 2, Left = 3;
enum Moves { Up, Right, Down, Left };

#define canGoUp(i, siz)     (i >= siz)
#define canGoRight(i, siz)  ((i + 1) % siz)
#define canGoDown(i, siz)   ((i / siz + 1) < siz)
#define canGoLeft(i, siz)   (i % siz)

int getNextMove(char dir, int i, int siz, char *x) {
	int new_i;

	switch (dir) {
	case Up:
		new_i = i - siz;
		if (canGoUp(i, siz) && !x[new_i])
			return new_i;
		break;
	case Right:
		new_i = i + 1;
		if (canGoRight(i, siz) && !x[new_i])
			return new_i;
		break;
	case Down:
		new_i = i + siz;
		if (canGoDown(i, siz) && !x[new_i])
			return new_i;
		break;
	case Left:         // Left
		new_i = i - 1;
		if (canGoLeft(i, siz) && !x[new_i])
			return new_i;
		break;
	}
	return i;  // this should never happen anyway

}

void shaneWalk() {

	int grid[10][10];
	int fail = 0, dir, row = 0, column = 0;
	char letter = 'A';
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			grid[i][j] = dot;
	}
	
	grid[row][column] = letter;
//	srand((unsigned)time(NULL));
	
	while (fail < 4) {
		
		if (fail == 0) {
			dir = rand() % 4;
			if ( ++letter >'Z') break;
		}

		switch (dir) {
		case 0://up
			if (row> 0 && (grid[row-1][column] == dot)) {
				fail = 0;
				grid[--row][column] = letter;
				break; 
			}
			if (++fail == 4) break;
		case 1://right
			if (column<9 && (grid[row][column+1] == dot)) {
				fail = 0;
				grid[row][++column] = letter;
				break;
			}
			if (++fail == 4) break;
		case 2://down
			if (row < 9 && (grid[row+1][column] == dot)) {
				fail = 0;
				grid[++row][column] = letter;
				break;
			}
			if (++fail == 4) break;
		case 3://left
			if (column > 0 && (grid[row][column-1] == dot)) {
				fail = 0;
				grid[row][--column] = letter;
				break;
			}

			//if (++fail == 4) break;
			dir = 0;
			break;
		default:
			printf("uknown!\n");
			break;
		}
	}
	for (int printer1 = 0; printer1 <= 9; printer1++) {
		for (int printer2=0; printer2<= 9; printer2++)
			printf("%2c", grid[printer1][printer2]);
		printf("\n");
	}

}


void displayBoard(char *x, int len) {
	int max = len * len;

	// print the column #
	printf("\n----------\n   ");
	for (int i = 0; i < len; i++) {
		printf("%2d", i);
	}

	for (int i = 0; i < max; i++) {
		if (i % len == 0)
			printf("\n%3d", i / len); // print the row #
		printf("%2c", (x[i] ? x[i] : ' '));
	}
}

void alternativeWalk(char *x, int siz) {
	char move;
	int i = 0, nTries = 1, new_i = -1;
	char alpha = 'A';
	int maxTries = 4;  // just 4 times, Up, Right, Down, Left

	// exit when:
	// nTries ==5 if there is no successful move

	while (alpha <= 'Z' && nTries <= maxTries) {
		nTries = 0;
		move = (rand() % maxTries);

		while (++nTries <= maxTries) {
			new_i = getNextMove(move, i, siz, x);
			if (new_i != i) {
				i = new_i;
				x[i] = alpha++;
				break;
			}
			move = (move + 1) % 4;  // Up to Right, ... Left back to Up
		}
		displayBoard(x, siz);
	}
}

void simpleWalk(char *x, int siz) {
	char move;
	int i = 0, tries = 1, new_i;
	char alpha = 'A';
	int maxTries = 4;  // just 4 times, Up, Right, Down, Left

	bool set = false;

	for (i = 0; alpha <= 'Z' && tries <= maxTries; set = false) {
		tries = 1;
		move = rand() % maxTries;
		while (tries <= maxTries && !set) {
			switch (move) {
			case Up:
				if (tries++ % (maxTries + 1) == 0)
					break;
				new_i = i - siz;
				if ((i >= siz) && !x[new_i]) {
					set = true;
					break;
				}
				move = Right;
			case Right:
				if (tries++ % (maxTries + 1) == 0)
					break;
				new_i = i + 1;
				if ((i + 1) % siz && !x[new_i]) {
					set = true;
					break;
				}
				move = Down;
			case Down:
				if (tries++ % (maxTries + 1) == 0)
					break;
				new_i = i + siz;
				if ((i / siz + 1) < siz && !x[new_i]) {
					set = true;
					break;
				}
				move = Left;
			case Left:
				if (tries++ % (maxTries + 1) == 0)
					break;
				new_i = i - 1;
				if ((i % siz) && !x[new_i]) {
					set = true;
					break;
				}
				move = Up;
				break;
			}  // case switch

			if (set) {
				x[new_i] = alpha++;
				i = new_i;
				--tries;
			}
		}// either still cannot find a alot after exceeding max 4 tries or complete to Z

		displayBoard(x, siz);
	}

}


int main() {
	char ch;
	srand(time(NULL));

	//simpleWalk(x, siz);
	//alternativeWalk(x, siz);
	do {
		shaneWalk();
	} while ((ch = getchar()) != 'q');
		
	system("pause");
	return 43; // change 2 
}


