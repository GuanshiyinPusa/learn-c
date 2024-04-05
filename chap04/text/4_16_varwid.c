/* varwid.c -- use variable-width output field */
#include <stdio.h>

int main(void) {
	unsigned width, precision;
	int number = 256;
	double weight = 242.5;

	printf("What field width?\n");
	scanf("%d", &width);
	printf("The number is: %*d:\n", width, number);
	printf("Now enter a width and a precision: \n");
	scanf("%d %d", &width, &precision);
	printf("Weight = %*.*f\n", width, precision, weight);
	return 0;
}

// Output:
// What field width?
// 10
// The number is:        256:
// Now enter a width and a precision:
// 12 4
// Weight =     242.5000
