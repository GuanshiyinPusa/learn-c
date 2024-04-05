/*
Write a program that creates an eight-element array of ints and sets the
elements to the first eight powers of 2 and then prints the values. Use a for
loop to set the values, and, for variety, use a do while loop to display the
values.
*/

#include <stdio.h>

int main(void) {
	int arr[8];
	int i = 0;
	int power = 1;

	do {
		arr[i] = power;
		power *= 2;
		i++;
	} while (i < 8);

	i = 0;
	do {
		printf("%d ", arr[i]);
		i++;
	} while (i < 8);
	printf("\n");

	return 0;
}
