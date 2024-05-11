// Write a function called transform() that takes four arguments: the name of a
// source array containing type double data, the name of a target array of type
// double, an int representing the number of array elements, and the name of a
// function (or, equivalently, a pointer to a function). The transform()
// function should apply the indicated function to each element in the source
// array, placing the return value in the target array. For example, the call
// transform(source, target, 100, sin);
// would set target[0] to sin(source[0]), and so on, for 100 elements. Test the
// function in a program that calls transform() four times, using two functions
// from the math.h library and two suitable functions of your own devising as
// arguments to successive calls of the transform() function.

#include <math.h>
#include <stdio.h>

// Function prototypes
void transform(double *source, double *target, int n, double (*func)(double));
double doubleVal(double num);
double halfVal(double num);

int main() {
	double source[100], target[100];
	int i;

	// Initialize source array
	for (i = 0; i < 100; i++) {
		source[i] = i;
	}

	// Apply sin function
	transform(source, target, 100, sin);
	printf("Applied sin function. target[0] = %f\n", target[0]);

	// Apply cos function
	transform(source, target, 100, cos);
	printf("Applied cos function. target[0] = %f\n", target[0]);

	// Apply doubleVal function
	transform(source, target, 100, doubleVal);
	printf("Applied doubleVal function. target[0] = %f\n", target[0]);

	// Apply halfVal function
	transform(source, target, 100, halfVal);
	printf("Applied halfVal function. target[0] = %f\n", target[0]);

	return 0;
}

void transform(double *source, double *target, int n, double (*func)(double)) {
	int i;
	for (i = 0; i < n; i++) {
		target[i] = func(source[i]);
	}
}

double doubleVal(double num) { return 2 * num; }

double halfVal(double num) { return num / 2; }