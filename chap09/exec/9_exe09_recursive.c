#include <stdio.h>

double power(double n, int p); // ANSI prototype

int main(void) {
	double x, xpow;
	int exp;
	printf("Enter a number and the integer power");
	printf(" to which\nthe number will be raised. Enter q");
	printf(" to quit.\n");
	while (scanf("%lf%d", &x, &exp) == 2) {
		xpow = power(x, exp); // function call
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip -- bye!\n");
	return 0;
}

double power(double n, int p) { // function definition using recursion
	if (n == 0.0 && p == 0) {
		// 0^0 is undefined, but use 1 for this context
		printf("0 to the 0 is undefined, using a value of 1.\n");
		return 1.0;
	} else if (n == 0.0) {
		// 0 to any other power is 0
		return 0.0;
	} else if (p == 0) {
		// Any number to the 0 power is 1
		return 1.0;
	} else if (p < 0) {
		// Recursively calculate for negative powers
		return 1 / power(n, -p);
	} else {
		// Recursive step for positive powers
		return n * power(n, p - 1);
	}
}
