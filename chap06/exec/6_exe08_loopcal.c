/*
Write a program that requests two floating-point numbers and prints the value of
their difference divided by their product. Have the program loop through pairs
of input values until the user enters nonnumeric input.
*/

#include <stdio.h>

int main(void) {
	float a, b;
	printf("Give me two floating number:\n");
	while (scanf("%f %f", &a, &b)) {
		printf("diff = %f\n", a - b);
		printf("Prod = %f\n", a * b);
		printf("div = %.2f\n", (a - b) / (a * b));
	}
	return 0;
}
