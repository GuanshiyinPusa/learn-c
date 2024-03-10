/*
There are 2.54 centimeters to the inch. Write a program that asks you to enter
your height in inches and then displays your height in centimeters. Or, if you
prefer, ask for the height in centimeters and convert that to inches.
*/
#include <stdio.h>

int main(void) {
	double height_in_inches;
	double height_in_cm;
	const double cm_per_inch = 2.54;

	// Ask the user for their height in inches
	printf("Enter your height in inches: ");
	scanf("%lf", &height_in_inches);

	// Convert height from inches to centimeters
	height_in_cm = height_in_inches * cm_per_inch;

	// Display the height in centimeters
	printf("Your height in centimeters is: %.2f cm\n", height_in_cm);

	return 0;
}

/*
 * Output:
 * Enter your height in inches: 72
 * Your height in centimeters is: 182.88 cm
 */
