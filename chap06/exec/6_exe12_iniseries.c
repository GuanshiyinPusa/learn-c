/*
Consider these two infinite series:
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
Write a program that evaluates running totals of these two series up to some
limit of number of terms. Hint: –1 times itself an odd number of times is –1,
and –1 times itself an even number of times is 1. Have the user enter the limit
interactively; let a zero or negative value terminate input. Look at the running
totals after 100 terms, 1000 terms, 10,000 terms. Does either series appear to
be converging to some value?
*/

#include <stdio.h>

int main(void) {
	int limit;
	double sum1 = 0.0, sum2 = 0.0;

	printf("Enter the limit of number of terms: ");
	scanf("%d", &limit);
	while (limit > 0) {
		for (int i = 1; i <= limit; i++) {
			sum1 += 1.0 / i;
			if (i % 2 == 0) {
				sum2 -= 1.0 / i;
			} else {
				sum2 += 1.0 / i;
			}
		}
		printf(
			"The sum of the first series up to %d terms is %.5f\n", limit,
			sum1);
		printf(
			"The sum of the second series up to %d terms is %.5f\n", limit,
			sum2);
		printf("Enter the limit of number of terms: ");
		scanf("%d", &limit);
	}
	printf("Done\n");

	return 0;
}
