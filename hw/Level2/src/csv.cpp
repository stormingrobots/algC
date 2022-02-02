// Sorting csv project
// Only skeleton work to identify the high level structure of this project
// Author: Storming Robots
// Date:  March 23rd, 2020
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <common.h>


#pragma warning(disable:4996)

#define MAX 255         // em

enum enTypes { NumericType, StringType, DateType };
enum enOrder { Acsending, Desending };

struct sortCategory {
    char catName[MAX];
    enTypes type = NumericType;
    enOrder mode = Acsending;
    //when take into account A or D char direction;
};

struct SortListStruct {
    char* beg;
    char* theField;
    char* end;
};


int compareInt(const void*, const void*);
int compareString(const void*, const void*);
int compareDate(const void*, const void*);

int (*compare[]) (const void*, const void*) = { compareInt, compareString, compareDate };


size_t getsize(FILE * fp);

int match(int num, int* possible, int length); //in step 4

void parseArgs(char *[], int, sortCategory*);
//  char* generate(void);
#define pause   system("pause");        //em


void fillSortedList(char* p, int nCols, SortListStruct *list) {

    list->beg = p;
    list->end = strchr(p, '\n');

    //   list->theField = 
  
}


int compareInt(const void* p, const void* q) {
    return 0;
}

int compareString(const void* p, const void* q) {
    return 0;

}

int compareDate(const void* p, const void* q) {
    return 0;
}

// parse from args to cats
// e.g. age|N|A
void parseArgs(const char*args[], int ct,  sortCategory **cats) {

    return;
}


// fill columns[] with which columns for sorting
// return # of sorting columns
int parseHeaderRow(char *row, sortCategory *cats, int *columns ) {
    int n = 0;
  

    return n;
}

// parse a single column for sorting
int parseHeaderRow(char* row, sortCategory* cats)  {
    int n = 0;


    return n;
}


size_t getEstimatedRows(const char* fname, char **buf) {
    size_t fsize; 0;
    FILE* fpin = fopen(fname, "r");
    if (fpin == NULL)
        exit(0);
    printf("%zu ", fsize = getsize(fpin));
    *buf = (char*)malloc( (size_t)(fsize + 1));
    size_t n = fread(buf, 1, (int)fsize, fpin);
    (*buf)[n] = 0;
    fclose(fpin);
    return (fsize / MAX);
}

/**/
size_t getsize(FILE* fp) {
    size_t size;
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return size;
}


int match(int num, int* possible, int length) {
    for (int i = 0; i < length; i++) {
        if (num == possible[i])
            return 1;
    }
    return 0;
}

void wt(const char* fname, int nRecords, SortListStruct *list) {


    return;
}

// 
// e.g. 
// const char* args[4] = { processName, "input.txt", "age", "N", "name", "S" };
int csv( int argc, const char *args[]) {
    sortCategory *cats;
    char* fileData; 
    const char* fname;
    uInt estimatedRows;
    SortListStruct* list;
    char* p;
    int nCols;     // single column for sorting.
         // int* columns;  if you are going to have multiple columns
     
  
    fname = args[1];

    estimatedRows = (uInt) getEstimatedRows(fname, &fileData);  // (args[1] has the input file name
    parseArgs(args, argc, &cats); // find out what users wants to sort by in what order and type
   
    p = fileData;
         // nCols = parseHeaderRow(p, cats, columns);   // if there are multiple sorted columns 
    nCols= parseHeaderRow(p, cats);

    list = (SortListStruct*) malloc(estimatedRows * sizeof(SortListStruct));
   
    int nRecords;
    char* lineBreak;
    for (nRecords=0, lineBreak=0; lineBreak = strchr(p, '\n'); nRecords++) {
        // parse one line at a time to fill the sort data structure    
        fillSortedList(p, nCols, list);

        // need to re-alloc if it goes over nEstimatedRows
    }
    
    qsort(list, nRecords, sizeof(*list), compare[ cats->type ] );
    wt(fname, nRecords, list);
    return 0;
}
