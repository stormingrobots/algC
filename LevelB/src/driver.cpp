#include "levelB.h"

// ABSOLUTELY NO GLOBALS
// do not use scanf_s, or any MS proprietory APIs
int main() {
	int sel;
	// at the end of ch. 6 - have them worked on the selection \
	// uing switch case - see the packet online - "multiple files ... "
	// have them complete this for ch. 5 and 6 functions 

	do {
		printf("Enter exercise # 1 to 10 (0 == terminate) :   ");
		printf("   1: doBills \n");
		printf("   2: doLoan \n");
		printf("   3: doTrade \n");
		printf("   4: base10to8 \n");
		printf("   5:  doGCD\n");
		printf("   6: doFraction \n");
		printf("   7: displaySqrs \n");
		printf("   8: calendar \n");
		printf("   9: sum_of_e \n");

		scanf("%d", &sel);

		switch (sel) {
		case 1: doBills(); break;
		case 2: doLoan(); break;
			// etc. 
		case 0: break;
		default: printf("********* Invalue input! \n\n");
				continue;
		}

	} while (sel != 0);
	return 0;
}