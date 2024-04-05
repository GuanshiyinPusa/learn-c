// divisors.c -- nested ifs display divisors of a number
#include <stdbool.h>
#include <stdio.h>

int main(void) {
	unsigned long num; // number to be checked
	unsigned long div; // potential divisors
	bool isPrime;	   // prime flag
	printf("Please enter an integer for analysis; ");
	printf("Enter q to quit.\n");
	while (scanf("%lu", &num) == 1) {
		for (div = 2, isPrime = true; (div * div) <= num; div++) {
			if (num % div == 0) {
				if ((div * div) != num)
					printf("%lu is divisible by %lu and %lu.\n", num, div,
						   num / div);
				else
					printf("%lu is divisible by %lu.\n", num, div);
				isPrime = false; // number is not prime
			}
		}
		if (isPrime)
			printf("%lu is prime.\n", num);
		printf("Please enter another integer for analysis; ");
		printf("Enter q to quit.\n");
	}
	printf("Bye.\n");
	return 0;
}

// Output:
// Please enter another integer for analysis; Enter q to quit.
// 3456789
// 3456789 is divisible by 3 and 1152263.
// 3456789 is divisible by 7 and 493827.
// 3456789 is divisible by 21 and 164609.
// 3456789 is divisible by 97 and 35637.
// 3456789 is divisible by 291 and 11879.
// 3456789 is divisible by 679 and 5091.
// 3456789 is divisible by 1697 and 2037.
// Please enter another integer for analysis; Enter q to quit.
// q
// Bye.
