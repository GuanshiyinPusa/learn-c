/*
Write a program that reads in a floating-point number and prints it first in
decimal-point notation, then in exponential notation, and then, if your system
supports it, p notation. Have the output use the following format (the actual
number of digits displayed for the exponent depends on the system): Enter a
floating-point value: 64.25 fixed-point notation: 64.250000 exponential
notation: 6.425000e+01 p notation: 0x1.01p+6
*/
#include <stdio.h>

int main() {
	double number;

	// Prompt the user for input
	printf("Enter a floating-point value: ");
	scanf("%lf", &number);

	// Print in fixed-point notation
	printf("fixed-point notation: %.6f\n", number);

	// Print in exponential notation
	printf("exponential notation: %.6e\n", number);

	// Print in p notation (hexadecimal floating-point notation)
	// Note: %a specifier is used for p notation. It's part of C99 standard.
	printf("p notation: %a\n", number);

	return 0;
}

/*
 * Output:
 * Enter a floating-point value: 64.25
 * fixed-point notation: 64.250000
 * exponential notation: 6.425000e+01
 * p notation: 0x1.01p+6
 */
