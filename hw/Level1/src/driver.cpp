
#include <ch7.h>
#include <ch8.h>
#include <myStruct.h>
#include <myEnum.h>

// use array of pointers to functions only in level III. 
// level I & II students should just simply use switch case 
// for the whole list. 

void (*level1_MainFuncs[])() = { ch7Main, ch8Main, structMain, enumMain };
char level1_MainFuncsNames[][20] = {
	"ch7Main", "ch8Main", "structMain", "enumMain" };


int main() {
	int maxSel = sizeof(level1_MainFuncsNames) / sizeof(level1_MainFuncsNames[0]);
	
	mainTemplate(level1_MainFuncs, level1_MainFuncsNames, maxSel);

/*	int sel = 0;
	int maxSel = sizeof(level1_MainFuncsNames) / sizeof(level1_MainFuncsNames[0]);
	do {
		printf("=============================\nWhich one to run?\n");
		for (int i = 0; i < maxSel; i++) {
			printf("\t%d for %s\n", i+1, level1_MainFuncsNames[i]);
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
		
		level1_MainFuncs[--sel]();
	} while (1);
*/
}
