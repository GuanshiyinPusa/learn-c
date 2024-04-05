/* Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power()
function that returned the result of raising a type double number to a positive
integer value. Improve the function so that it correctly handles negative
powers. Also, build into the function that 0 to any power other than 0 is 0 and
that any number to the 0 power is 1. (It should report that 0 to the 0 is
undefined, then say it’s using a value of 1.) Use a loop. Test the function in a
program. */
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

double power(double n, int p) { // function definition
	if (n == 0.0 && p == 0) {
		printf("0 to the 0 is undefined, using a value of 1.\n");
		return 1.0; // 0^0 is undefined, but use 1 for this context
	} else if (n == 0.0) {
		return 0.0; // 0 to any other power is 0
	} else if (p == 0) {
		return 1.0; // Any number to the 0 power is 1
	} else {
		double pow = 1.0;
		int i,
			positive_p = p > 0 ? p : -p; // Use positive exponent for the loop

		for (i = 1; i <= positive_p; i++) {
			pow *= n;
		}

		if (p < 0) {
			pow = 1.0 / pow; // Invert the result for negative powers
		}

		return pow; // return the calculated power
	}
}
