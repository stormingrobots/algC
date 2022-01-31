
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <common.h>

#include <ch11.h>
#include <ch12.h>
#include <stringModule.h>
#include <bitwiseOperations.h>
#include <struct_2.h>
#include <fileIO.h>
#include <recursion.h>
#include <srchSort.h>

#ifdef _WIN32
#include <conio.h>
#endif

char exNames[][10] = {
	 "ch11", "ch12", "ch13", "recursion", "bitwise", "fileIO", "srchSort" };

void (*chapterMains[])() = { ch11, ch12, ch13, recursion, bitwise, fileIO, srchSort };


int main() {
	int select = 0;
	int maxselect = sizeof(chapterMains) / sizeof(chapterMains[0]);
	do {
		printf("=============================\nWhich one to run?\n");
		for (int i = 0; i < maxselect; i++) {
			printf("\t%d for %s\n", i + 1, exNames[i]);
		}
		printf("\nEnter 0 to terminate!\n");
		printf("-------------------------\n");
		printf("select: ");

		select = (int)getNum();
		if (select == 0) break;
		if (select < 0 || select > maxselect) {
			printf("Invalid selection. Valid [ 1 to %d ] !\n", maxselect);
			continue;
		}

		chapterMains[--select]();

	} while (1);

}

