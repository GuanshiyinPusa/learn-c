/*
In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces,
an ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program that
requests a volume in cups and that displays the equivalent volumes in pints,
ounces, tablespoons, and teaspoons. Why does a floating-point type make more
sense for this application than an integer type?
*/
#include <stdio.h>

int main(void) {
	double cups;
	double pints, ounces, tablespoons, teaspoons;

	// Conversion constants
	const double CUPS_TO_PINTS = 0.5;
	const double CUPS_TO_OUNCES = 8.0;
	const double CUPS_TO_TABLESPOONS =
		8.0 * 2.0; // 1 cup = 8 ounces, 1 ounce = 2 tablespoons
	const double CUPS_TO_TEASPOONS =
		8.0 * 2.0 * 3.0; // 1 cup = 8 ounces, 1 ounce = 2 tablespoons, 1
						 // tablespoon = 3 teaspoons

	// Request volume in cups from the user
	printf("Enter the volume in cups: ");
	scanf("%lf", &cups);

	// Calculate equivalent volumes
	pints = cups * CUPS_TO_PINTS;
	ounces = cups * CUPS_TO_OUNCES;
	tablespoons = cups * CUPS_TO_TABLESPOONS;
	teaspoons = cups * CUPS_TO_TEASPOONS;

	// Display the equivalent volumes
	printf("Equivalent volumes:\n");
	printf("%.2f cups is equivalent to:\n", cups);
	printf("%.2f pints\n", pints);
	printf("%.2f ounces\n", ounces);
	printf("%.2f tablespoons\n", tablespoons);
	printf("%.2f teaspoons\n", teaspoons);

	return 0;
}

/*
 * Output:
 * Enter the volume in cups: 2
 * Equivalent volumes:
 * 2.00 cups is equivalent to:
 * 1.00 pints
 * 16.00 ounces
 * 32.00 tablespoons
 * 96.00 teaspoons
 */
