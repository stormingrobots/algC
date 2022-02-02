#include <levelB.h>

// proj #?
void checkM() {
    int m;
    printf("enter a number: ");
    scanf("%d", &m);

    if (0 <= m && m <= 9) {
        printf("the number %d has one digit", m);
    }
    // make sure all students will remove the redundant bool exp, such as 
    // 10 <= m
    if (m <= 99) {
        printf("the number %d has two digits", m);
    }
    if (m <= 999) {
        printf("the number %d has three digits", m);
    }
    if (m <= 9999) {
        printf("the number %d has four digits", m);
    }
    else {
    //else if (m > 9999)< --  make sure they won't do this.
        printf("number too large");
    }
}

// proj #?
void hrmm() {
    int h, m;
    printf("enter 24-hour time: ");
    scanf("%d:%d", &h, &m);

    // make sure they will do error checking
    if (h > 23 || m > 59 || h < 0 || m < 0) {
        printf("Invalid input HH:MM - %02d:%02d\n", h, m);
        return;
    }

    if (h >= 12) {
        h = h - 12;
        printf("equivalent 12 hr time: %d:%d PM", h, m);
    }
    if (h < 12) {
        printf("equivalent 12 hr time: %d:%d AM", h, m);
    }
}

// proj #?
// minimize them using just i, or j, etc.
void doIncome() {
    double income;

    printf("enter income ");
    scanf("%lf", &income);
    if (income< 750) {
        income= income* .01;
        // should not do it here..    printf("tax due: %f", i);
    }
    // no redundant bool exp :  if (income>= 750 && income<= 2250) {
    else if (income <= 2250) {
        income= 7.5 + ((income- 750) * .02);
    }
    else if (income<= 3750) {
        income= 37.5 + ((income- 2250) * .03);
    }
    else if (income<= 5250) {
        income= 82.5 + ((income- 3750) * .04);
    }
    else if (income<= 7000) {
        income= 142.5 + ((income- 5250) * .05);
    }
    else 
        income= 230 + ((income- 7000) * .06);

    printf("tax due: %f", income);
}

// proj 7
// ONLY 4 ifs.
//    remember divide and conquer : 
void smallest_largest_with4_ifs() {

    int a, b, c, d;
    int sml1, lgt1, sml2, lgt2;

    printf("enter four intergers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    sml1 = (a < b ? a : b);
    lgt1 = (a > b ? a : b);

    sml2 = (c < d ? c : d);
    lgt2 = (c > d ? c : d);

    sml1 = (sml1 < sml2 ? sml1 : sml2);
    lgt1 = (lgt1 > lgt2 ? lgt1 : lgt2);

    printf("largest: %d smallest %d", lgt1, sml1);

}


// project 9
bool isLeap(int yr) {
    return (yr % 4 == 0 && (yr % 100 == 0 && yr % 400 == 0));
}

void checkDate() {
   
        int yr1, mth1, day1, yr2, mth2, day2;
        printf("Input a date in this format: MM/DD/YY\n");
        scanf("%d/%d/%d", &mth1, &day1, &yr1);
        printf("Input a date in this format: MM/DD/YY\n");
        scanf("%d/%d/%d", &mth2, &day2, &yr2);

    // challenge those ahead to do error checking ------------------
        if (!((mth1 >= 1 && mth1 <= 12) && (mth2 >= 1 && mth2 <= 12))) {
            printf("Invalid date!");
            return;
        }

        int maxFebDays1 = (isLeap(yr1) ? 29 : 28);
        int maxFebDays2 = (isLeap(yr2) ? 29 : 28);

        if ((day1 < 1  || (mth1==2 && day1 > maxFebDays1) )  ||
            (day2 < 1 || (mth2 == 2 && day2 > maxFebDays2))
           )
        {
            printf("Invalid date!");
            return;
        }

        int num1 = yr1 * 10000 + mth1 * 100 + day1;
        int num2 = yr2 * 10000 + mth2 * 100 + day2;

        if (num1 == num2)
            printf("Same Date.\n");
        else if (num1 < num2)
            printf("Date  %02d/%02d/%02d\n",  yr1, mth1, day1);
        else
            printf("Date  %02d/%02d/%02d\n", yr2, mth2, day2);

}

//Project 10
void showGrade() {
    int grade;

    printf("input grade: ");
    scanf("%d", &grade);

    if (grade > 10 || grade < 0 ){
        printf("Invalid Grade. Enter 0 to 100!\n");
        return;
    }
    
    grade = grade / 10;
    switch (grade) {
 /*  BAD!!!!
    case 1: printf("F");
        break;
    case 2: printf("F");
        break;
    case 3: printf("F");
        break;
    case 4: printf("F");
        break;
    case 5: printf("F");
        break;
  */
    case 10:
    case 9: printf("A");
        break;
    case 8: printf("B");
        break;
    case 7: printf("C");
        break;
    case 6: printf("D");
        break;
    default:  printf("F");
        break;
    }
}
