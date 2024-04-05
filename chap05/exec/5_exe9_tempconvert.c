/*
Write a program that requests the user to enter a Fahrenheit temperature. The
program should read the temperature as a type double number and pass it as an
argument to a user-supplied function called Temperatures(). This function should
calculate the Celsius equivalent and the Kelvin equivalent and display all three
temperatures with a precision of two places to the right of the decimal. It
should identify each value with the temperature scale it represents. Here is the
formula for converting Fahrenheit to Celsius: Celsius = 5.0 / 9.0 * (Fahrenheit
- 32.0) The Kelvin scale, commonly used in science, is a scale in which 0
represents absolute zero, the lower limit to possible temperatures. Here is the
formula for converting Celsius to Kelvin: Kelvin = Celsius + 273.16 The
Temperatures() function should use const to create symbolic representations of
the three constants that appear in the conversions. The main() function should
use a loop to allow the user to enter temperatures repeatedly, stopping when a q
or other nonnumeric value is entered. Use the fact that scanf() returns the
number of items read, so it will return 1 if it reads a number, but it won’t
return 1 if the user enters q. The
== operator tests for equality, so you can use it to compare the return value of
scanf() with 1.
*/

#include <stdio.h>
#define FAHRENHEIT_TO_CELSIUS 5.0 / 9.0
#define FAHRENHEIT_TO_KELVIN 273.16
void Temperatures(double fahrenheit);

int main(void) {
	double fahrenheit;
	printf("Enter a Fahrenheit temperature: ");
	while (scanf("%lf", &fahrenheit) == 1) {
		Temperatures(fahrenheit);
		printf("Enter a Fahrenheit temperature (q to quit): ");
	}
	printf("Bye!\n");
	return 0;
}

void Temperatures(double fahrenheit) {
	const double celsius = FAHRENHEIT_TO_CELSIUS * (fahrenheit - 32.0);
	const double kelvin = celsius + FAHRENHEIT_TO_KELVIN;
	printf("%.2f Fahrenheit is %.2f Celsius and %.2f Kelvin.\n", fahrenheit,
		   celsius, kelvin);
}

// Output:
// Enter a Fahrenheit temperature: 32
// 32.00 Fahrenheit is 0.00 Celsius and 273.16 Kelvin.
// Enter a Fahrenheit temperature (q to quit): 212
// 212.00 Fahrenheit is 100.00 Celsius and 373.16 Kelvin.
// Enter a Fahrenheit temperature (q to quit): 0
// 0.00 Fahrenheit is -17.78 Celsius and 255.38 Kelvin.
// Enter a Fahrenheit temperature (q to quit): q
// Bye!
