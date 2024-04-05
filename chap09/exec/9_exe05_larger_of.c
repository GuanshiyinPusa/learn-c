/* Write and test a function called larger_of() that replaces the contents of
two double variables with the maximum of the two values. For example,
larger_of(x,y) would reset both x and y to the larger of the two. */

#include <stdio.h>
void larger_of(double *, double *);

void larger_of(double *x, double *y) {
	double larger = (*x > *y) ? *x : *y;
	*x = larger;
	*y = larger;
}

int main(void) {
	double x = 5.0, y = 10.0;
	printf("Originally x = %.2f and y = %.2f.\n", x, y);
	larger_of(&x, &y); // send address to function
	printf("Now x = %.2f and y = %.2f.\n", x, y);

	return 0;
}
