/*
Write a program that reads eight integers into an array and then prints them in
reverse order.
*/

#include <stdio.h>

int main(void) {
	int arr[8];

	printf("Enter 8 integers: ");
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}

	printf("The integers in reverse order: ");
	for (int i = 7; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

// Output:
// Enter 8 integers: 1 2 3 4 5 6 7 8
// The integers in reverse order: 8 7 6 5 4 3 2 1
