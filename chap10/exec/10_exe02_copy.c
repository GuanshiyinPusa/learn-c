/* Write a program that initializes an array-of-double and then copies the
contents of the array into three other arrays. (All four arrays should be
declared in the main program.) */
// TODO: To make the first copy, use a function with array
// notation.
// TODO: To make the second copy, use a function with pointer notation and
// pointer incrementing.

/* Have the first two functions take as arguments the name of
the target array, the name of the source array, and the number of elements to be
copied. Have the third function take as arguments the name of the target, the
name of the source, and a pointer to the element following the last element of
the source. That is, the function calls would look like this, given the
following declarations:
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];
double target3[5];
copy_arr(target1, source, 5);
copy_ptr(target2, source, 5);
copy_ptrs(target3, source, source + 5); */

#include <stdio.h>
#define SIZE 5
void copy_arr(double target1[], const double source[], int n);
void copy_ptr(double *target2, const double *source, int n);
void copy_ptrs(double *target3, const double *start, const double *end);

int main(void) {
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, SIZE);
	copy_ptr(target2, source, SIZE);
	copy_ptrs(target3, source, source + SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%.1f\t", target1[i]);
	}
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%.1f\t", target2[i]);
	}
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%.1f\t", target3[i]);
	}
	printf("\n");
}

void copy_arr(double *target1, const double *source, int n) {
	for (int i = 0; i < n; i++)
		target1[i] = source[i];
}

void copy_ptr(double *target2, const double *source, int n) {
	for (int i = 0; i < n; i++)
		*(target2 + i) = *(source + i);
};

void copy_ptrs(double *target3, const double *start, const double *end) {
	while (start < end)
		*target3++ = *start++;
};
