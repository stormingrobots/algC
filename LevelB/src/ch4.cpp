
#include "levelB.h"

// proj #?
void base10to8() {
	
	// only need 5 digits, because: 
	//   32768  =   8^5 -1
	// 	 i.e.  8^4 +  8^3 +  8^2 +  8^1 + 8
	// largest # under 32768 in based-8 is = 77777 (base 8)
	//  77777 (base 8) == 32767

	// can be used as their 1st exercise to work on in class
	// by the time they reach ch. 8

	int d1, d2, d3, d4, d5, num, n;

	printf("positive integer below 32768: ");
	scanf("%d", &num);
	n = num;
	// should do error checking
	if (n > 32767) {
		printf("Must enter below 32768\n");
		return;
	}

	d1 = n % 8;
	n = n / 8;

	d2 = n % 8;
	n = n / 8;

	d3 = n % 8;
	n = n / 8;

	d4 = n % 8;
	n = n / 8;

	d5 = n % 8;

	printf("%d(base-8) = %d%d%d%d%d", num, d5, d4, d3, d2, d1);

}


