// boolean.c -- using a _Bool variable
#include <stdio.h>

int main(void) {
	long num;
	long sum = 0L;
	_Bool input_is_good;
	printf("Please enter an integer to be summed ");
	printf("(q to quit): ");
	input_is_good = (scanf("%ld", &num) == 1);
	while (input_is_good) {
		sum = sum + num;
		printf("Please enter next integer (q to quit): ");
		input_is_good = (scanf("%ld", &num) == 1);
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
