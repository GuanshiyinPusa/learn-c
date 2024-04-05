#include <stdio.h>

unsigned long long Fibonacci(int n);

int main(void) {
	int n;
	printf("Enter the position of the Fibonacci number you wish to find (n >= "
		   "0):\n");
	while (scanf("%d", &n) == 1 && n >= 0) {
		printf("Fibonacci number at position %d is %llu\n", n, Fibonacci(n));
		printf("Enter another position (q to quit):\n");
	}
	printf("Done.\n");
	return 0;
}

unsigned long long Fibonacci(int n) {
	if (n == 0)
		return 0; // First Fibonacci number is 0
	if (n == 1)
		return 1; // Second Fibonacci number is 1

	unsigned long long prev = 0; // Initial value for Fibonacci(0)
	unsigned long long curr = 1; // Initial value for Fibonacci(1)
	unsigned long long next;

	for (int i = 2; i <= n; i++) {
		next = prev + curr; // The next number is the sum of the previous two
		prev = curr;		// Update previous number
		curr = next;		// Update current number
	}

	return curr; // Return the nth Fibonacci number
}
