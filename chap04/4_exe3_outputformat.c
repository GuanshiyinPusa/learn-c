/*
Write a program that reads in a floating-point number and prints it first in
decimal-point notation and then in exponential notation. Have the output use the
following formats (the number of digits shown in the exponent may be different
for your system): a. The input is 21.3 or 2.1e+001. b. The input is +21.290
or 2.129E+001.
*/

#include <stdio.h>
int main(void) {
	float number;

	printf("Please enter a floating-point number:\n");
	scanf("%f", &number);
	printf("The input is %.1f or %.1e\n", number, number);
	printf("The input is %+0.3f or %.3E\n", number, number);

	return 0;
}

// Output:
// Please enter a floating-point number:
// 3.40
// The input is 3.4 or 3.4e+00
// The input is +3.400 or 3.400E+00
