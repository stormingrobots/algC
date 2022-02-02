
#define ME
// ME vesrion is the fastest in the worse case senario, and takes a more constant speed no
// matter how many recursive occurence
// the only reasons byte-by-byte is more efficient is because other memmove or strstr method will:
//  - need to move string back multiple times
//  -  how bad it is depends on how recursive occurence gets
// 
// DoMem vesrion :
// it proves strstr is very  as going it byte by byte //.
//#define DoMEM

#ifdef ME
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define MAX 1000001
#define MAX 1000001

int main()
{
	int censorLen;
	int srcLen;
	time_t beg = clock();
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	char *src = (char *)malloc(MAX);
	char *target = (char *)malloc(MAX);
	char censor[101];
	memset(censor, NULL, sizeof(censor));
	memset(target, NULL, sizeof(MAX));
	memset(src, NULL, MAX);

	scanf("%s", src);
	scanf("%s", censor);
	censorLen = strlen(censor);
	srcLen = strlen(src);

// method 1 : 2.8 sec

#ifdef DoMEM

	char *p;
	int leftover;
	p = src;

	p = strstr(p, censor);
	while (p)
	{	 
		leftover = srcLen - (p + censorLen - src);
		memmove(p, p + censorLen, leftover);
		srcLen -=  censorLen;
		*(src + srcLen) = 0;
		p = strstr(src, censor);
	}
	puts(src);
#else
	int i, targetPos;

	for (i = 0, targetPos=0; i < srcLen; i++)
	{
		target[targetPos++] = src[i];
		if (targetPos >= censorLen &&  memcmp(&target[targetPos-censorLen], censor, censorLen)==0)
			targetPos -= censorLen;
	}
	target[targetPos] = 0;
	puts(target);
#endif // DoMEM

	
#else
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;
using std::cin;

int main() {
	clock_t beg = clock();
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);

	/* Read input strings. */
	string S, T;
	std::cin >> S >> T;

	/* Build R, the result string, one character at a time. */
	string R;
	for (int i = 0; i < S.size(); i++) {
		R += S[i];

		/* If the end of R matches T then delete it. */
		if (R.size() >= T.size() && R.substr(R.size() - T.size()) == T) {
			R.resize(R.size() - T.size());
		}
	}

	cout << R << endl;
#endif
	long t = clock() - beg;
	//	freopen("/dev/stdout", "w", stdout);	
	printf("\n\n%ld\n", t);

	return 0;
}

	
