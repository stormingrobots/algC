// String manipulation functions
// Author: Neha Vardhaman
// Date: March 27, 2020

#include <stringModule.h>
#include <recursion.h>

#include <common.h>

void ch13() {
	printf("Do string exs selection... \n");
	return;
}

//saves the address of each substring occurrence and returns the number of occurrences
int findSubStrings(char *pstr, char *substr, char *location[]) {
	uLLong substrLen = strlen(substr);
	int n = 0;
	char *p;
	while (*pstr != 0) {
		p = strstr(pstr, substr);
		if (p != 0) {
			location[n] = p;
			n++;
			pstr = p + substrLen;
		} else {
			break;
		}
	}
	return n;
}


//returns the address of the last substring occurrence
const char *findLastSubString(const char *str, char const *substr) {
	size_t strLen = strlen(str);
	size_t substrLen = strlen(substr);

	const char *pstr = str;

	// reverse the original string
	char* newP = (char*)calloc(strLen+1, 1);
	if (!newP) {
		printf("Error! %d \n", errno);
		return NULL;
	}
	memcpy(newP, str, strLen);
	reverseString(newP);
	
	// reverse the original sub string
	char* newSubP = (char*)calloc(substrLen+1, 1);
	if (!newSubP) {
		printf("Error! %d \n", errno);
		return NULL;
	}
	memcpy(newSubP, substr, substrLen);
	reverseString(newSubP);
	
	// get the location and calculate the proper location
	char* p = strstr(newP, newSubP);

	size_t bytesIn = p - newP + substrLen;
	bytesIn = strLen - bytesIn; 

	return str+ bytesIn;
}

//replaces all substring occurrences
// EM: this will not handle recursive substring such as mmoooo

void strstrReplace(char *str, char *substr1, char *substr2) {
	char str2[10001];
	char *pstr = str, *pstr2 = str2, *psubstr1;
	size_t substr1Len = strlen(substr1), substr2Len = strlen(substr2);
	for (; (psubstr1 = strstr(pstr, substr1)) != 0;) {
		memcpy(pstr2, pstr, psubstr1 - pstr);
		pstr2 += psubstr1 - pstr;
		memcpy(pstr2, substr2, substr2Len);
		pstr2 += substr2Len;
		pstr = psubstr1 + substr1Len;
	}
	strcpy(pstr2, pstr);
	strcpy(str, str2);
}

//removes all substring occurrences
void strrem(char str[], char str2[], char substr[]) {
	size_t substrLen = strlen(substr);
	size_t strLen = strlen(str);
	char *pstr = str, *pstr2 = str2;
	char *pstrEnd = pstr + strLen;
	if ((pstr = strstr(str, substr)) != 0) {
		pstr2 += pstr - str;
		pstr += substrLen;
		while (pstr2 >= str2 && pstr <= pstrEnd) {
			*pstr2 = *pstr;
			if (memcmp(pstr2 - (substrLen - 1), substr, substrLen) == 0) {
				pstr2 -= (substrLen - 1);
				pstr++;
			}
			else {
				pstr2++;
				pstr++;
			}
		}
	}
}


void doFindLastSubString(int argc, char *argv[]) {
	const int max = 1000;
	char* str = (char*)calloc(max, 1);
	char* subStr = (char*)calloc(max, 1);
	if (!str || !subStr) {
		printf("Error! %d \n", errno);
		exit(-1);
	}

	cout << argv[0] << endl;

	if (argc >= 3) {
		memcpy(str, argv[1], min(strlen(argv[1]), max));
		memcpy(subStr, argv[2], min(strlen(argv[2]), max));
	}
	else {
		const char* p = "How much wood would a woodchuck chuck woodchuck chuck!";
		memcpy(str, p, strlen(p));
		memcpy(subStr, "wood", 4);
	}
	fgets(str, max, stdin);

	const char* p2 = findLastSubString(str, subStr);
	cout << "the last " << subStr << " locates at " << " byte-" << p2 - str << ". (0 & up)";
	free(str);
	free(subStr);
}