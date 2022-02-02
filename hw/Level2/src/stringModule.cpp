

// String manipulation functions
// Author:  Some by Neha Vardhaman, and some by Storming Robots
// Date: March 27, 2020

#include <stringModule.h>
#include <recursion.h>

#include <common.h>

// by Storming Robots
// Do note:  This pointer to function methods should not be introduced 
//           until level 3. 
char ch13FuncsNames[][30] = {
	 "find substring",  "find last substring",  "replace all substrings", "momomoo" };

void (*ch13Funcs[])() = { findSubStrings, findLastSubString, replaceStrs, fmoomoo2 };

void ch13() {
		int select = 0;
		int maxselect = sizeof(ch13Funcs) / sizeof(ch13Funcs[0]);
		do {
			printf("=============================\nWhich one to run?\n");
			for (int i = 0; i < maxselect; i++) {
				printf("\t%d for %s\n", i + 1, ch13FuncsNames[i]);
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

			ch13Funcs[--select]();

		} while (1);

	}




void replaceStrs() {
	printf("Do string exs selection... \n");
	char sent[] = "Farmer John loves Johntown, and eats at dinnerJohnPlace. Fun Johnny!";
	printf("new:  %s\n", replaceStrs(sent, "John", "Benjamin"));
	return;
}


void findSubStrings() {
	char** loc = (char**)calloc(100, sizeof(char*));  // just for testing
	char str[100] = "Farmer John lives i Johnstown, and loves DinerJohnny!";
	printf("find # of Substrings:  %d\n",
		findSubStrings(str, "John", loc));
}

void findLastSubString() {
	char str[100] = "Farmer John lives i Johnstown, and loves DinerJohnny!";
	printf("last location of Substrings:  %p\n",
		findLastSubString(str, "John"));
}

// Author:  Neha Vardhaman
//saves the address of each substring occurrence and returns the number of occurrences
int findSubStrings(char* pstr, const char* substr, char* location[]) {
	size_t substrLen = strlen(substr);
	int n = 0;
	char* p;
	while (*pstr != 0) {
		p = strstr(pstr, substr);
		if (p != 0) {
			location[n] = p;
			n++;
			pstr = p + substrLen;
		}
		else {
			break;
		}
	}
	return n;
}

// Author:  Neha Vardhaman
//returns the address of the last substring occurrence
const char* findLastSubString(const char* str, char const* substr) {
	size_t strLen = strlen(str);
	size_t substrLen = strlen(substr);

	const char* pstr = str;

	// reverse the original string
	char* newP = (char*)calloc(strLen + 1, 1);
	if (!newP) {
		printf("Error! %d \n", errno);
		return NULL;
	}
	memcpy(newP, str, strLen);

	//EM: IMPORTANT note:  Neha used her own recursive reverseString function. 
	// Students at this chapter usually have not learnt recursion
	// so, should expect them writing a simple loop to do so. 
	// have them just writing a function
	reverseString(newP);

	// reverse the original sub string
	char* newSubP = (char*)calloc(substrLen + 1, 1);
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

	return str + bytesIn;
}

// Author:  Neha Vardhaman
//removes all substring occurrences
void strrem(char str[], char str2[], char substr[]) {
	size_t substrLen = strlen(substr);
	size_t strLen = strlen(str);
	char* pstr = str, * pstr2 = str2;
	char* pstrEnd = pstr + strLen;
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

// Author:  Neha Vardhaman
void doFindLastSubString(int argc, char* argv[]) {
	const int max = 1000;
	char* str = (char*)calloc(max, 1);
	char* subStr = (char*)calloc(max, 1);
	if (!str || !subStr) {
		printf("Error! %d \n", errno);
		exit(-1);
	}

	cout << argv[0] << endl;

	if (argc >= 3) {
		memcpy(str, argv[1], Min(strlen(argv[1]), max));
		memcpy(subStr, argv[2], Min(strlen(argv[2]), max));
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

// ==================================================================
// Author:  Storming Robots:
// replaces all substring occurrences
// pre-allocate for the new sentence 
// since I have to traverse the old sentence, I may as well save 
// the location of each old str. 
// Do note:  the routine of creating a sentence is really short. 
//           20-25% of the code is for error checking. 
// Do not use this for handling the recursive substring such as mmoooo exercise 

char* replaceStrs(char* sentence, const char* old_subStr, const char* new_subStr) {
	char* newSentence;				// the new Sentence
	char* pOld = sentence;			// moving pointer traversing the original str 
	size_t old_subStrLen = strlen(old_subStr);
	size_t new_subStrLen = strlen(new_subStr);
	int nWords = 0;

	// allocate memory for the new string  --------------------------------------
	char* pEnd = sentence + strlen(sentence);
	size_t maxReplacement = strlen(sentence) / 10;
	char** pos = (char**)calloc(maxReplacement, sizeof(char*)); // save the addr or all old_subStr

	if (pos == NULL) {
		return NULL;
	}

	if (old_subStrLen >= new_subStrLen) {
		newSentence = (char*)calloc(strlen(sentence) + 1, 1);
	}
	else {

		for (nWords = 0; (pOld = strstr(pOld, old_subStr)) != 0; nWords++, pOld++) {
			if (nWords >= maxReplacement) {
				maxReplacement *= 2;
				pos = (char**)realloc(pos, maxReplacement);
				if (pos == NULL) {
					return NULL;
				}
			}
			pos[nWords] = pOld;
		}
		newSentence = (char*)calloc(strlen(sentence) +
			nWords * (new_subStrLen - old_subStrLen) + 1, 1);
	}
	if (newSentence == NULL) {
		return NULL;
	}
	// end of pre-allocating memory for the new sentence
	//-----------------------------------------------------

	pOld = sentence;
	char* pNew = newSentence;
	size_t nToCopy = 0;
	for (int i = 0; i < nWords; i++) {
		// copy the chunk between old_substr
		nToCopy = pos[i] - pOld;
		memcpy(pNew, pOld, nToCopy);

		// copy the new_substr
		pNew = pNew + nToCopy;
		memcpy(pNew, new_subStr, new_subStrLen);
		pNew = pNew + new_subStrLen;

		// advance the pointer to the next word
		pOld = pos[i] + old_subStrLen;
	}

	// copy the rest...
	nToCopy = pEnd - pOld;
	memcpy(pNew, pOld, nToCopy);

	free(pos);
	return newSentence;
}

