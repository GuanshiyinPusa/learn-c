/* floats.c -- some floating-point combinations */
#include <stdio.h>

int main(void) {
	const double RENT = 3852.99; // const-style constant
	// other ways to use const
	const unsigned int MONTHS = 12;
	const double RENT2 = 3852.99;

	printf("*%f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3e*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("*%010.2f*\n", RENT);

	printf("*%u*\n", MONTHS);
	printf("*%#x*\n", MONTHS);

	printf("*%f*\n", RENT2);

	return 0;
}

// Output:
// *3852.990000*
// *3.852990e+03*
// *3852.99*
// *3853.0*
// *  3852.990*
// * 3.853e+03*
// *+3852.99*
// *0003852.99*
// *12*
// *0xc*
// *3852.990000*
