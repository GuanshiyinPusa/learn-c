/* skippart.c -- uses continue to skip part of loop */
#include <stdio.h>

int main(void) {
	const float MIN = 0.0f;
	const float MAX = 100.0f;
	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;
	printf("Enter the first score (q to quit): ");
	while (scanf("%f", &score) == 1) {
		if (score < MIN || score > MAX) {
			printf("%0.1f is an invalid value. Try again: ", score);
			continue; // jumps to while loop test condition
		}
		printf("Accepting %0.1f:\n", score);
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		n++;
		printf("Enter next score (q to quit): ");
	}
	if (n > 0) {
		printf("Average of %d scores is %0.1f.\n", n, total / n);
		printf("Low = %0.1f, high = %0.1f\n", min, max);
	} else
		printf("No valid scores were entered.\n");
	return 0;
}

// Output:
// Enter the first score (q to quit): 12
// Accepting 12.0:
// Enter next score (q to quit): 5
// Accepting 5.0:
// Enter next score (q to quit): -2.5
// -2.5 is an invalid value. Try again: 0
// Accepting 0.0:
// Enter next score (q to quit): q
// Average of 3 scores is 5.8.
// Low = 0.0, high = 12.0
