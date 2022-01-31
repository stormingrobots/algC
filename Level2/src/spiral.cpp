#include <stdio.h>
#include <stdarg.h>
#include <varargs.h>

const int maxRows = 7, maxCols = 6;
int x[maxRows][maxCols];
int total = maxRows * maxCols;
enum enType { fill, prt };
int sum=0;

int eachCycle(int R, int C, int Val) {
	int ct = 0;
	bool toRight = true;
	
	do {
		// do Col - 1 times,  +1 for each
		
		for (int i=1 ; i <C && sum<total; i++, sum++) {
			printf("%3d, ", (toRight ? Val++ : Val--));
		}
		if (R == 1) {
			printf("%3d, ", Val); break;
		}
		printf("\n------------\n");
		
		for (int i = 1; i < R && sum<total; i++, sum++) {
			printf("%3d, ", Val);
			Val = Val + maxCols * (toRight ? 1 : -1);
		}
		//printf("%3d, ", Val);
		

		printf("\n------------\n");
		toRight = false;

	} while ( ++ct < 2);
	Val = Val + maxCols + 1;

	printf("\n=======\n");
	return Val;
}

void fillArray(int R, int C, enType work) {

	// just to fill the array
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			if (work == fill)
				x[i][j] = i * C + j;
			else
				printf("%3d ", x[i][j]);
		if (work == prt) printf("\n");
	}
}

// proper implementation with an 1-D array

void doSpiral() {
	int row, col, firstNum = 0;

	fillArray(maxRows, maxCols, fill);
	fillArray(maxRows, maxCols, prt);

	for (row = maxRows, col = maxCols; col >= 1 && row >= 1; row -= 2, col -= 2)
		firstNum = eachCycle(row, col, firstNum);
}

void doSpiralLong() {
	const int maxCols = 7;
	int nums[][maxCols] =
	{
		{1,2,3,4,5,6,7},
		{8,9,10,11,12,13,14},
		{15,16,17,18,19,20,21}
	};
	int maxRows = sizeof(nums) / sizeof(nums[0]);
	int last_row = maxRows - 1;
	int last_col = maxCols - 1;


	//while (beg_row <=last_row && beg_col <= last_col)
	for (int beg_col = 0, beg_row = 0;
		beg_row <= last_row && beg_col <= last_col;
		++beg_row, ++beg_col, --last_row, --last_col)
	{

		for (int i = beg_col; i < last_col; ++i)
		{
			printf("%d ", nums[beg_row][i]);
		}
		//++beg_col;
		printf("; ");
		for (int i = beg_row; i < last_row; ++i)
		{
			printf("%d ", nums[i][last_col]);
		}
		//++beg_row;
		printf("; ");
		if (beg_row == last_row) {
			printf("%d ", nums[last_row][last_col]);
			//do something;
		}
		else {
			for (int i = last_col; i > beg_col; --i)
			{
				printf("%d ", nums[last_row][i]);
			}
		}
		//--last_col;
		printf("; ");

		//	for (int i = last_row; i >= beg_row; --i)
		for (int i = last_row; i > beg_row; --i)
		{
			//	printf("%d ", nums[i][beg_col - 1]);
			printf("%d ", nums[i][beg_col]);
		}
		//--last_row;
		printf("\n");
	}
}
