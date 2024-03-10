/* summing.c -- sums integers entered interactively */
#include <stdio.h>
int main(void) {
	long num;
	long sum = 0L;
	/* initialize sum to zero */
	int status;
	printf("Please enter an integer to be summed ");
	printf("(q to quit): ");
	status = scanf("%ld", &num);
	while (status == 1) /* == means "is equal to" */
	{
		sum = sum + num;
		printf("Please enter next integer (q to quit): ");
		status = scanf("%ld", &num);
	}
	printf("Those integers sum to %ld.\n", sum);
	return 0;
}

// Path: 6_2_summing.c
/*
Please enter an integer to be summed (q to quit): 1
Please enter next integer (q to quit): 2
Please enter next integer (q to quit): 3
Please enter next integer (q to quit): 4
Please enter next integer (q to quit): q
Those integers sum to 10.
*/
