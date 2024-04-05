/* Write and test a function that takes the addresses of three double variables
as arguments and that moves the value of the smallest variable into the first
variable, the middle value to the second variable, and the largest value into
the third variable. */

#include <stdio.h>

void orderThree(int *x, int *y, int *z) {
	int temp;

	// Ensure that *x <= *y
	if (*x > *y) {
		temp = *x;
		*x = *y;
		*y = temp;
	}

	// Ensure that *y <= *z
	if (*y > *z) {
		temp = *y;
		*y = *z;
		*z = temp;
	}

	// Re-check *x <= *y as *y might have changed
	if (*x > *y) {
		temp = *x;
		*x = *y;
		*y = temp;
	}
}

int main() {
	int a = 14, b = 5, c = 9;

	// Reassign a, b, c to their values from smallest to largest
	orderThree(&a, &b, &c);

	printf("Ordered: a = %d, b = %d, c = %d\n", a, b, c);

	return 0;
}
