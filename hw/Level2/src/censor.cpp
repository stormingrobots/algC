
// Target codes for Level II  
// Author: Storming Robots
// Date:  March 23rd, 2020
// 

// ----------dec 2014 / 15 - Bronze & Silver
#include "../level1/common.h"

void _censoring(const char* src, const char* censor, char* target)
{
	char* newp = target;
	char* oldp = (char*)src;

	int censorLen = (int)strlen(censor); // 3 if "moo"

	char* lowestP = target + censorLen - 1;
	for (int len = censorLen - 1; *oldp; ++newp, ++oldp)
	{
		*newp = *oldp;
		if (newp < lowestP) continue;  // 

		if (memcmp(newp - len, censor, censorLen) == 0)
			newp -= censorLen;
	}
	*newp = 0;
}


void censoring(bool useFile)
{
	showMe;
	clock_t beg = clock();

	char* target = (char*)malloc(usacoMAX + 1);
	memset(target, 0, usacoMAX + 1);

	char* sentence = (char*)malloc(usacoMAX + 1);
	memset(sentence, NULL, usacoMAX + 1);

	char censor[101] = { 0 };

	if (useFile) {
		// redirect file as stdin and stdout
		FILE * fp= freopen("censor.in", "r", stdin);   //redirect stdin to input file
		freopen("censor.out", "w", stdout); //redirect stdout to out file
		fgets(sentence, usacoMAX + 1, stdin);
		scanf("%s", censor);
	}
	else {
		strcpy(sentence, "momoooFarmer John mmmmoooooooo cow momoom");
		strcpy(censor, "moo");
	}
	
	_censoring(sentence, censor, target);

	printf("%s\n", target);

	if (useFile) {
		freopen("/dev/stdout", "w", stdout);  // redirect stdout back to default
	}
	long t = clock() - beg;
	return;
}
