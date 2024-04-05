/* The harmonic mean of two numbers is obtained by taking the inverses of the
two numbers, averaging them, and taking the inverse of the result. Write a
function that takes two double arguments and returns the harmonic mean of the
two numbers.*/
#include <stdio.h>
double harmonic_mean(double, double);

double harmonic_mean(double a, double b) { return 2 / (1 / a + 1 / b); }

int main(void) {
	printf("%f\n", harmonic_mean(2.3, 2.4));
	return 0;
}
