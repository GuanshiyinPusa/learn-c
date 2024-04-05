/* day_mon2.c -- letting the compiler count elements */
#include <stdio.h>

int main(void) {
	const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
	int index;
	for (index = 0; index < sizeof(days) / sizeof(days[0]); index++)
		printf("Month %2d has %d days.\n", index + 1, days[index]);
	// if we are not able to count correctly, we use sizeof days -- the size in
	// bytes of the whole array, divide by sizeof the first element of the array
	// Disadvantage of automatic counting: Errors in the number of elelments
	// could pass unnoticed.
}
