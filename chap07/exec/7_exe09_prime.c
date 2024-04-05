/*
Write a program that accepts a positive integer as input and then displays all
the prime numbers smaller than or equal to that number.
*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
	int num;
	bool isPrime;
	printf("Enter a positive integer: ");
	scanf("%d", &num);
	for (int i = 2; i <= num; i++) {
		isPrime = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}

// Output:
// Enter a positive integer: 13
// 2 3 5 7 11 13
