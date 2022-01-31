
#include <baseConv.h>
#include <ch7.h>
#include <ch8.h>
#include <myStruct.h>
#include <myEnum.h>

// use array of pointers to functions only in level III. 
// level I & II students should just simply use switch case 
// for the whole list. 

int (*chapterMains[])() = { baseConvMain, ch7Main, ch8Main, structMain, enumMain };
char exNames[][10] = {
	 "baseConv", "ch7", "ch8", "struct", "enum" };

int main() {
	int sel = 0;
	int maxSel = sizeof(chapterMains) / sizeof(chapterMains[0]);
	do {
		printf("=============================\nWhich one to run?\n");
		for (int i = 0; i < maxSel; i++) {
			printf("\t%d for %s\n", i+1, exNames[i]);
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
		
		chapterMains[--sel]();
	} while (1);

}
