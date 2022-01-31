
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <common.h>
//#include <varargs.h>
#include<stdarg.h>
#include<time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


#ifdef _WIN32
void sleep(float sec)
{
	Sleep(sec *1000);
}
#else
void sleep(float sec)
{
	usleep(sec * 1000); // microseconds
}
#endif


//-------------------------------------------
// for Arduino - printf with variable list argument 
// can be a really handy function for Arduino platform
void printRGB(const char* msg, ...)
{
	va_list list;
	va_start(list, msg);
	int argInt;
	char* argStr;

	for (const char* p = msg; *p; ++p)
	{
		if (*p != '%') {
			putchar(*p);
			continue;
		}

		++p;
		if (*p == NULL) {
			break; // invalid % usage .. ignore and stop printing
		}
		switch (*p) {
		case 'r':
			argInt = va_arg(list, int);
			printf("d:%3d  x:%03x ", argInt &0x00ff0000 >> 16, argInt & 0x00ff0000 >> 16);
			break;
		case 'g':
			argStr = va_arg(list, int);
			printf("d:%3d  x:%03x ", argInt & 0x00ff0000 >> 8, argInt & 0x00ff0000 >> 8);
			break;
		case 'b':
			argInt = va_arg(list, int);
			printf(" (%s) ", argStr);
			break;
		case 's':
			argStr = va_arg(list, char*);
			printf("d:%3d  x:%03x ", argInt & 0x000000ff, argInt & 0x000000ff);
			break;
		default:  // include %%
			putchar(*p);
			break;
		}
	}
	return;
}


//------------------------

int getNext(const char* list, char sym, bool* done) {

	static char* p = NULL;
	if (p == NULL) {
		p = (char*)calloc(strlen(list) + 1, sizeof(char));
		if (!p) exit(-1);
		memcpy(p, list, strlen(list) + 1);
	}

	char* end = NULL;

	end = strchr(p, sym);
	if (end != NULL) // if null,  the end of the list
		*end = 0;
	int n = atoi(p);
	if (end != NULL) // if null,  the end of the list
		p = end + 1;
	else
	{
		p = NULL;
		*done = true;
	}

	return n;
}



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

