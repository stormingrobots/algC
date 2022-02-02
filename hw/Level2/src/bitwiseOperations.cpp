//Author: Neha Vardhaman
//Date: March 27, 2020

#include <bitwiseOperations.h>

void bitwise() {
	return;
}

int add(int num1, int num2) {
	int a = num1, b = num2, carryOver;
	while ((carryOver = (num1 & num2) << 1) != 0) {
		num2 = num1 ^ num2;
		num1 = carryOver;
	}
	return num1 ^ num2;
}

int subtract(int num1, int num2) {
	return add(num1, add(~num2, 1));
}

int multiply(int num1, int num2) {
	int r = 0;
	int a = num1, b = num2, c, d;
	while (true) {
		c = a << 1;
		d = b >> 1;
		if ((b & 1) == 1) {
			r = add(r, a);
		}
		if (d == 1)
			break;
		a = c;
		b = d;
	}
	return add(c, r);
}

void divide(int num1, int num2, int *rem, int *quotient) {
	int a, b = num2;
	int q = 1;
	while ((b << 1) <= num1) {
		b = b << 1;
		q = q << 1;
		*quotient = add(*quotient, q);
	}
	a = subtract(num1, b);
	if (a > num2) {
		divide(a, num2, rem, quotient);
	} else if (a < num2) {
		*rem = a;
	} else if (a == num2) {
		*quotient = add(*quotient, 1);
	}
}
