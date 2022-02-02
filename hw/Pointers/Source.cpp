#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxRows = 10, maxCols = 20;

void print2D(int* list, int rows, int cols) {
	for (int r = 0; r < rows; r++) {
		printf("%3d: ", r + 1);
		for (int c = 0; c < cols; c++)
			printf("%3d ", *(list + (r * cols) + c));
		printf("\n");
	}
	printf("------------------------------\n");
}


void print2D(int** list, int rows, int cols) {

	for (int r = 0; r < rows; r++) {
		printf("%3d: ", r + 1);
		for (int c = 0; c < cols; c++)
			printf("%3d ", list[r][c]);
		printf("\n");
	}
	printf("------------------------------\n");
}

int** create2D(int r, int c) {
	int** dp2 = (int**)malloc(sizeof(int*));
	if (dp2 == NULL) return NULL;

	*dp2 = (int*)calloc(r * c, sizeof(int));

	for (int i = 1; i < r; i++) {
		dp2[i] = (int*)((char*)dp2[i - 1] + sizeof(int) * c);
	}
	return (dp2);
}


int main() {

	// create a static list for testing -------------------
	int list[maxRows][maxCols];

	for (int i = 0; i < maxRows; i++) {
		for (int j = 0; j < maxCols; j++) {
			list[i][j] = i * j + j;
		}
	}
	print2D((int*)list, maxRows, maxCols);
	//----------------------------------

	int** dp = create2D(maxRows, maxCols);

	printf("\n\n");

	memcpy(*dp, (int*)list, maxRows * maxCols * sizeof(list[0][0]));

	print2D(*dp, maxRows, maxCols);
	print2D(dp, maxRows, maxCols);
	for (int i = 0; i < maxRows; i++) {
		printf("%3d: ", i);
		for (int j = 0; j < maxCols; j++) {
			printf("%3d ", dp[i][j]);
		}
		printf("\n");
	}
}

