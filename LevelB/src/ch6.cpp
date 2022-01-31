#include "levelB.h"


//EM: REMOVE all global variables
// NO goto statements
// IMPORTANT: in class, challenge them to perform a do { } while instead.  


//Chapter 6: exercises 11, 12, 13, 14
//Programming projects 1 - 4, 6, 8, 11
// 
// 
//Proj ?
// make sure they will use the Euclid algorithm stated in the book and 
// explain why it is far more effient - far less iterations
//    
void doGCD() {
    int n, m, r;

    printf("enter 2 numbers num1,num2: ");
    scanf("%d,%d", &n, &m);

    printf("gcd of %d, %d = ", n, m);
    while ((r = n % m) > 0) {
        n = m;
        m = r;
    }
    printf( "%d\n", m);
}

// Project 2

// no UI should take place inside this version gcf function.
int gcf(int n, int m) {
    int r; 
    while ((r = n % m) > 0) {
        n = m;
        m = r;
    }
    return m;
}

void doFraction() {
    int n, m;
    printf("enter an unsimplified fraction (x/x): ");
    scanf("%d/%d", &n, &m);
    int d = gcf(n, m);
    printf("%d/%d = %d/%d", n, m, n/d, m/d);
}

//Project 4
void doTrade() {
    float commission, value;
    while (1) {
        printf("Enter value of trade: ");
        scanf("%f", &value);
        if (value == 0) {
            break;
        }
        if (value < 2500.00f) {
            commission = 30.00f + .017f * value;
        }
        else if (value < 6250.00f) {
            commission = 56.00f + .0066f * value;
        }
        else if (value < 20000.00f) {
            commission = 76.00f + .0034f * value;
        }
        else if (value < 50000.00f) {
            commission = 100.00f + .0022f * value;
        }
        else if (value < 500000.00f) {
            commission = 155.00f + .0011f * value;
        }
        else
            commission = 255.00f + .0009f * value;

        if (commission < 39.00f)
            commission = 39.00f;

        printf("Commission: $%.2f\n", commission);
    }
}

//Project 6
// tell them use proper variable name
void displaySqrs() {
    int max, sqr;
    printf("enter number: ");
    scanf("%d", &max);
    for (int n = 2; (sqr = n * n) <= max; n += 2)
        printf("%d\n", sqr);

}

//Project 8
// make sure they use proper variable name
   /* do not let them do the following just to print \n
        if (i == 14 - w) {
            printf("\n");
        }
        if (i == 21 - w) {
            printf("\n");
        }
        if (i == 28 - w) {
            printf("\n");
        }
    */
void calendar() {
    int days, startday;
    printf("number of days in month: ");
    scanf("%d", &days);
    printf("starting day of the week; ");
    scanf("%d", &startday);
 
    printf("%*c", (startday-1)*3, ' '); // assuming 3 spaces per day
    // or
   /*
   for (int i = 1; i < startday; i++) {
        printf("%3c", ' ');
    }
    */
    
    for (int i = 1; i <= days; i++) {
        printf("%3d", i);
        if ((startday + i - 1) % 7 == 0)
            printf("\n");
    }
}


//Project 11
void sum_of_e() {
    int n, fact = 1;
    double sum = 1;
    printf("enter number: ");
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) {
        fact = fact * i; 
        sum = sum +  1 / fact;
    }
    printf("sum(e) up to the %d term = %lf\n", n, sum);
}

