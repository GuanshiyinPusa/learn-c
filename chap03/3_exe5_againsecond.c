// Write a program that requests your age and the equivalent number of seconds.

#include <stdio.h>

int main(void) {
	double secondsinyear = 3.156e7;
	int age;
	scanf("Input age%d\n", &age);
	printf("Age in seconds %e\n", age * secondsinyear);
	return 0;
}

/*
 * Output:
 * Input age 20
 * Age in seconds 6.312000e+08
 */
