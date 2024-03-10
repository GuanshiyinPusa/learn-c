/*
Write a program that sets a type double variable to 1.0/3.0 and a type float
variable to 1.0/3.0. Display each result three times—once showing four digits to
the right of the decimal, once showing 12 digits to the right of the decimal,
and once showing 16 digits to the right of the decimal. Also have the program
include float.h and display the values of FLT_DIG and DBL_DIG. Are the displayed
values of 1.0/3.0 consistent with these values?
*/
#include <float.h>
#include <stdio.h>
int main(void) {
	double d = 1.0 / 3.0;
	float f = 1.0 / 3.0;
	printf("double: %.4f %.12f %.16f\n", d, d, d);
	printf("float: %.4f %.12f %.16f\n", f, f, f);
	printf("FLT_DIG: %d\n", FLT_DIG);
	printf("DBL_DIG: %d\n", DBL_DIG);
	return 0;
}

// Output:
// double: 0.3333 0.333333333333 0.3333333333333333
// float: 0.3333 0.333333343267 0.3333333432674408
// FLT_DIG: 6
// DBL_DIG: 15
