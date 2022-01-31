#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void randomArray(const char* readFileName, const char* writeFileName) {
	FILE* rfp = fopen(readFileName, "r");
	FILE* wfp = fopen(writeFileName, "wb");
	if (!rfp || !wfp) {
		return;
	}
	int x, y;
	fscanf(rfp, "%d %d", &x, &y);
	int* arr = (int*)malloc(sizeof(int) * x * y);
	for (int i = 0; i < x * y; i++) {
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			fprintf(wfp, "%d\t", arr[i * y + j]);
		}
		fprintf(wfp, "\n");
	}
	fprintf(wfp, "\n");
	fclose(wfp);
}

void randomArray(const char *fname) {
	FILE* wfp = fopen(fname, "w");
	if (!wfp) {
		return;
	}
	const int x=3, y=4;
	
	int arr[x*y];

	for (int i = 0; i < x * y; i++) {
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			fprintf(wfp, "%d\t", arr[i * y + j]);
		}
		fprintf(wfp, "\n");
	}
	fprintf(wfp, "\n");
}


int main() {

	 randomArray("c:/temp/test2.txt");

	FILE* fout = fopen("c:/temp/test.txt", "wb");
	if (fout == NULL)
		return -1;

	for (int i = 0; i < 5;  i++) {
		fprintf(fout, "%d + %d = %d\n", i, i, i + i);
	}
	fclose(fout);




	return -1;
}