// trouble.c -- misuse of =
// will cause infinite loop
#include <stdio.h>
int main(void) {
	long num;
	long sum = 0L;
	int status;
	printf("Please enter an integer to be summed ");
	printf("(q to quit): ");
	status = scanf("%ld", &num);
	while (status == 1) {
		// while (status = 1) {
		sum = sum + num;
		printf("Please enter next integer (q to quit): ");
		status = scanf("%ld", &num);
	}
	printf("Those integers sum to %ld.\n", sum);
	return 0;
}

// Output:
// Please enter an integer to be summed (q to quit): 1
// Please enter next integer (q to quit): 2
// Please enter next integer (q to quit): 3
// Please enter next integer (q to quit): q
// Those integers sum to 6.
