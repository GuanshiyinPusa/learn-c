/*
Write a program that requests a type double number and prints the value of the
number cubed. Use a function of your own design to cube the value and print it.
The main() program should pass the entered value to this function.
*/
#include <stdio.h>
double cubedouble(double num);

int main(void) {
	double num;
	printf("Enter a double number: ");
	scanf("%lf", &num);
	printf("The cube of %.2f is %.2f.\n", num, cubedouble(num));
	return 0;
}

double cubedouble(double num) { return num * num * num; }

// Output:
// Enter a double number: 5.0
// The cube of 5.00 is 125.00.
