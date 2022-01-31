
#include <stdio.h>
#pragma warning(disable:4996)	

// proj #?
void doBills() {
	int amt, bill;

		scanf("%d", &amt);	
		//cal $20 bills
		
		bill = 20;
		printf("$%d bills : %d\n", bill,  amt/bill);
		amt = amt % bill;

		//cal $10 bills
		bill = 10;
		printf("$%d bills : %d\n", bill, amt/bill);
		amt = amt % bill;

		//cal $5 bills
		bill = 5;
		printf("$%d bills : %d\n", bill, amt/bill);
		amt = amt % bill;

		//remaining $1 bills
		bill = 1;
		printf("$%d bills : %d\n", bill, amt);

	}

// proj #?
void doLoan() {
	float owe, rate, pay;

	printf("amount of loan:");
	scanf("%f", &owe);
	printf("interest rate:");
	scanf("%f", &rate);
	printf("enter monthly payment:");
	scanf("%f", &pay);

	owe = owe + owe * (rate / 100.0f) / 12.0f - pay;
	printf("Balance remaining after first payment: %.2f\n", owe);

	owe = owe + owe * (rate / 100.0f) / 12.0f - pay;
	printf("Balance remaining after second payment: %.2f\n", owe);

	owe = owe + owe * (rate / 100.0f) / 12.0f - pay;
	printf("Balance remaining after third payment: %.2f\n", owe);
}