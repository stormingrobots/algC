#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct some {
	int number;
};
void quicksortR(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
int compareSome(const void*, const void*);

some tinyList[] = { 31,5, 50,10, 40, 15, 2, 20, 30, 9, 5, 25 };
some* bigList = NULL;

void prtList(some* beg, some* end, int size) {

	for (int i = 0; beg <= end; i++, beg++) {
		printf("%d ", beg->number);
	}
	printf("\n");
	fflush(stdout);
}

int main(int argc, char *argv[])
{
	int nElements = sizeof(tinyList) / sizeof(tinyList[0]); // the default size

	if (argc <= 1) {
		printf("Old List:  ");
		prtList(tinyList, &tinyList[nElements - 1], sizeof(tinyList[0]));
	}
	else {
		nElements = atoi(argv[1]);
		srand(time(NULL));
		printf("Test with %d elements!\n",nElements);
		bigList = (some*)calloc(nElements + 1, sizeof(some));
		for (int i = 0; i < nElements; i++)
			bigList[i].number = rand() % nElements;
	}

	if (argc <= 1)
		quicksortR(tinyList, nElements, sizeof(tinyList[0]), compareSome);
	else
		quicksortR(bigList, nElements, sizeof(bigList[0]), compareSome);

	// check the result 
	if (argc <= 1) {
		printf("Sorted List:  ");
		prtList(tinyList, &tinyList[nElements - 1], sizeof(tinyList[0]));
	}
	else {
		int i;
		for (i = 1; i < nElements; i++) {
			if (bigList[i].number < bigList[i - 1].number) {
				printf("Failed Sorting!\n");
				break;
			}
		}
		if  (i==nElements)
			printf("Successful Sorting!\n");
	}

}

// return 1  : i > j
// return -1 : i < j
int compareSome(const void* i, const void* j) {
	some* a = (some*)i;
	some* b = (some*)j;
	if ((*a).number > (*b).number) {
		return 1;
	}
	else if ((*a).number < (*b).number) {
		return -1;
	}
	else {
		return 0;
	}
}
void swap(void* a, void* b, int size) {
	void* temp = (void*)malloc(sizeof(a));
	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
}

//  Revised generic qsort

enum Partition { lo, hi };

void quicksortR(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {
	
	char* end = (char*)base + size * (nmemb - 1);
#ifdef _TINY_
	prtList((some*)base, (some*)end, size);
#endif	
	if (nmemb <= (size_t)1) {
		return;
	}

	if (nmemb == (size_t)2) {
		char* p = ((char*)(base)+size);
		if (compar(base, p) == 1) {
			swap(base, p, size);
		}
		return;
	}
	
	// pick the 1st element to be the pivot------

	char* lower = (char*)base;
	char* upper = end;


	// since I pick 1st element to be the pivot, leave a hole at 1st element slot
	// you must keep track where the hole is, i.e. currently lower is pointing to the "hole"
	// you must start with the hi partition. 
	
	Partition part = hi; 

	for (int i = 0; lower < upper; i++) {
		
		// working on the upper partition
		if (part == hi) {	
			// if upper < lower
			if (compar(upper, lower) == -1) { 
										  // currently lower has the hole, place upper into the hole
				swap(upper, lower, size); // now the upper has the hole
				
				lower += size;			  // advance lower to the next element
				part = lo;				  // go to the lower partition
			}
			else
				upper -= size;				  // keep moving in as upper >= pivot
				
			continue;
		}

		// working on the lower partition		
		if (compar(lower, upper) == 1) {
				// currently upper has the hole, place lower value into the hole
				swap(upper, lower, size); // now the upper has the hole

				upper -= size;			  // advance lower to the next element
				part = hi;				  // go to the hi partition
		}
		else 
			lower += size;

	}
	quicksortR(base, (lower - (char*)base) / size, size, compar);
	quicksortR(lower + size, (end - lower)/size, size, compar);
}