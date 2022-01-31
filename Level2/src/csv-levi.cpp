#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

#pragma warning(disable:4996)

#define MAX 10

//Dont forget to move all of the type declarations to the beginning when possible
long getsize(FILE * fp);
void analyzelist(char* columns, char** name);
int match(int num, int* possible, int length); //in step 4
int compare(const void *p, const void *q);
char* generate(void);
void pause(void) {
    printf("\n");
    char pause = getchar();
}

struct category {
    char catName[MAX];
    char mode;
    //when take into account A or D char direction;
};
struct item {
    long address;
    union value {
        int integer;
        char string[MAX];
    } good;
};
/*char* generate(void) {
    srand(time(NULL));
    char* generate = (char*)malloc(3000);
    char* generatehelper = generate;
    char* base = (char*)"levi";
    char* insert = base;
    char* num = (char*)malloc(1);
    char* comma = (char*)",";
    char* newline = (char*)"\n";
    strcpy(generate, (char*)"Fname, Age\n");
    generate += (sizeof("Fname, Age\n") - 1);
    for (int i = 0; i < 100; i++) {
        strcat(generate, base); //add back strcat
        //memcpy(strcat((char*)i, base), generate, sizeof(strcat((char*)i, base)));
        generate += sizeof(base);
        strcat(generate, comma);
        generate++;
        *num = '0' + rand() % 10;
        memcpy(generate, num, 1); // problem
        generate++;
        strcpy(generate, newline);
        generate++;
        insert = base;
        //clear insert
    }
    *generate = '\0';
}
 */
int  main(int argc, char* argv[]) {
    printf("hidd");
    pause();
    //
    //STEP1 -- generate buffer
    //STEP1 -- read in the buffer
    FILE* fpin = fopen("test.txt", "r");
    if (fpin == NULL)
        exit(0);
    printf("%d ", getsize(fpin));
    char* list = (char*)malloc(getsize(fpin));
    int n = fread(list, 1, getsize(fpin), fpin);
    list[n] = '\0';
    printf("%s ", list);
    pause();
    fclose(fpin);
    char* point = list;
    char* helperpoint = point;
    //STEP1 -- read in the buffer
    //STEP2 -- parse the command line arguments
    //argv[0] is the file address
    printf("%s\n", argv[1]);
    struct category* cat = (category*)malloc(sizeof(struct category) * ((argc - 1) / 2));
    int count = 1, counthelper = 0;
    for (int i = 0; i < (argc - 1) / 2; i++) {
        counthelper = 0;
        for (int temp = count; count < temp + 2; count++) {
            if (count == temp) {
                for (char input = argv[count][counthelper]; input != '\0'; input = argv[count][++counthelper])
                    cat[i].catName[counthelper] = input;
            }
            else
                cat[i].mode = argv[count][0];
        }
        cat[i].catName[counthelper] = '\0';
    }
    for (int i = 0; i < ((argc - 1) / 2); i++)
        printf("\n%s %c", cat[i].catName, cat[i].mode);//
    pause();
    //STEP2 -- parse the command line arguments -- sucess -> stored in Cat
    //STEP3 -- parse through buffer to check how many lines there are, in order to allocate memory for the pointer to structure, also find out where each category is


    count = 0;
    int numOfLines = 0, spaces = 0, wordCount = 0, index = 0, numOfItemCount = 0; /*for first for loop*/
    int* numOfItem = (int*)malloc((argc - 1) / 2);//malloc this in future
    char* word = (char*)malloc(MAX);
    //find out where each category is -- parse through first line
    while (*point != '\n') {
        if (*point == ',') {
            word[wordCount] = '\0';
            wordCount = 0;
            for (int i = 0; i < (argc - 1) / 2; i++) {
                if (strcmp(word, cat[i].catName) == 0) {
                    numOfItem[numOfItemCount++] = spaces;
                    break;
                }
            }
            spaces++;
            point++;
        }
        else if (*point == ' ')
            point++;
        else {
            word[wordCount++] = *point;
            point++;
        }
    }
    /*for (char input = list[count++]; input != '\n'; input = list[count++]) { //THERE IS AN ISSUE WHERE DOB CANNOT BE READ BECAUSE OF HOW IT DOES NOT MATCH UP WITH ORIGINAL.
            //BECAUSE input contains \n
            if (input == ',') {
                word[wordCount] = '\0';
                for (int i = 0; i < (argc - 1) / 2; i++) {
                    if (strcmp(word, cat[i].catName) == 0) {
                        numOfItem[index++] = spaces;
                        break;
                    }
                }
                spaces++;
                wordCount = 0;
                count++;
            }
            else
                word[wordCount++] = input;
        }
        */
        //Count lines
    helperpoint = point;
    while (*point != '\0') {
        if (*point == '\n')
            numOfLines++;
        point++;
    }
    helperpoint++;
    point = helperpoint;
    for (int i = 0; i < ((argc - 1) / 2); i++)
        printf("%d", numOfItem[i]);
    printf("%c %c", *point, *helperpoint);
    pause(); //as of right here, both point and helperpoint point to the beginning of the second line
    /*for (char input = list[count++]; input != '\0'; input = list[count++]) {
        if (input == '\n')
            numOfLines++;
    }
    numOfLines++;
    /*
     numOfItems[0] = column # of a sorted field -1
     e.g.Age, DOB , I have
    */
    struct item* newList = (struct item*)malloc(numOfLines * sizeof(struct item));
    struct item* displayList = newList; //use later for displaying
    //STEP3 -- parse through buffer to check how many lines there are, in order to allocate memory for the pointer to structure
    //STEP4 -- parse through Buffer -> fill out newList



    wordCount = 0;
    int spacesCount = 0, numberIndex = 0, readCount = 0; //for main parse
    //char number[3]; //used to gather up string -- USE WORD INSTEAD
    for (int i = 0; i < MAX; i++)
        word[i] = '\0';
    pause();
    for (int i = 0; i < numOfLines; i++) {
        newList[i].address = (long)point;
        spacesCount = 0, numberIndex = 0, readCount = 0;
        for (int p = 0; p < MAX; p++)
            word[p] = '\0';
        while (readCount < ((argc - 1) / 2)) {
            point = strstr(helperpoint, (char*)","); //moves point to the next comma
            point++;
            if (match(spacesCount, numOfItem, ((argc - 1) / 2))) {
                helperpoint++; //to account for the space
                memcpy(word, helperpoint, point - helperpoint - 1);
                //add word into data structure
                for (int fill = 0; fill < (strlen(word) + 1); fill++)
                    newList[i].good.string[fill] = word[fill];//problem
                readCount++;
            }
            else {
                helperpoint = point; //moves helperpoint to point
                spacesCount++;
            }
        }
        if (i + 1 != numOfLines) {
            point = strstr(helperpoint, (char*)"\n");
            point++;
            helperpoint = point;
        }
    }
    for (int i = 0; i < numOfLines; i++)
         printf("%d %s\n", newList[i].address, newList[i].good.string);
    pause();
    //STEP4 -- parse through Buffer -> fill out newList
    //STEP5 -- Order the Array
    displayList = newList;
    qsort(newList, numOfLines + 1, sizeof(item), compare);
    for (int i = 0; i < numOfLines; i++) {
        printf("%d %s\n", newList[i].address, newList[i].good.string);
    }
    pause();
    //STEP5 -- Order the Array
    //STEP6 -- Write new data into old csv file //*THERE IS A PROBLEM WITH
    //A or D order, write the array backwards or forwards
    FILE* fpout = fopen("C:/Levi/C++/My C++ Program Files/ParsingArithmeticExpressions/output.txt", "w");
    if (fpin == NULL)
        exit(0);
    count = 0;
    for (char input = list[count++]; input != '\n'; input = list[count++])
        fputc(input, fpout);
    fputc('\n', fpout);

    point = list;
    for (int i = 0; i < numOfLines; i++) {
        point += (newList[i].address - (long)list);
        for (; *(point) != '\n' && *(point)!= '\0'; point++)
            fputc(*point, fpout);
        fputc('\n', fpout);
        point = list;
    }
    //for (int i = 0; i < numOfLines - 1; i++) {
        //for (int pos = newList[i].address; list[pos] != '\n'; pos++) {
            //fputc(list[pos], fpout);
        //}
        //fputc('\n', fpout);
    //}
    //fclose(fpout);
    //STEP6 -- Write new data into old csv file
}
/**/
long getsize(FILE* fp) {
    long size;
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return size;
}
void analyzelist(void* columns, void** name) {

    for (char input = ' '; input != '\n'; input++) {
        if (input == ' ' || input == ',')
            continue;
    }
}
int compare(const void *p, const void*q) {
    const struct item* p1 = (struct item*)p;
    const struct item* q1 = (struct item*)q;
    if (strcmp(p1->good.string, q1->good.string) < 0)
        return -1;
    else if (strcmp(p1->good.string, q1->good.string) == 0)
        return 0;
    else
        return 1;
}
int match(int num, int* possible, int length) {
    for (int i = 0; i < length; i++) {
        if (num == possible[i])
            return 1;
    }
    return 0;
}
