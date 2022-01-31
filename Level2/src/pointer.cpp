#include <common.h>
#include <ch11.h>


void ch11() {
	printf("Do ch11 selection... \n");
	return;
}

int adx(int a, int b) {
	return  (a + b);
}

int sub(int a, int b) {
	return  (a - b);
}
int (*func[])(int, int) = { adx, sub };



int compare(const void* p, const void* q) {
	//int compare(const void* p, const void* q) {

	return (*(int*)p > * (int*)q);
}


void doSimpleSortingNSearching() {
	int i = 0;
	int list[] = { -800, 10, -100, -400, 10, -900, -400, 10, -100, -400, 10, -100, -600 };
	int max = sizeof(list) / sizeof(list[0]);
	printf("\033[01;33m ========= qsort\n");
	qsort(list, max, sizeof(list[0]), compare);
	do {
		printf("%d%c ", list[i], (i == max - 1 ? '\n' : ','));
	} while (++i < max);

	int key = 140;

	int* addr = (int*)bsearch(&key, list, max, sizeof(list[0]), compare);

	printf("\033[01;31m org:%p  found: %p; diff = %zd \n", list, addr,
		(size_t)addr - (size_t)list);
	printf("\033[01;31m found %d at %zd\n", key, (addr - list) / sizeof(list[0]));
	// printf("\033[01;33m %d\n", 20);

	return;

}
