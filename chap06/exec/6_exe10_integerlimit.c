/*
Write a program that requests lower and upper integer limits, calculates the sum
of all the integer squares from the square of the lower limit to the square of
the upper limit, and displays the answer. The program should then continue to
prompt for limits and display answers until the user enters an upper limit that
is equal to or less than the lower limit. A sample run should look something
like this:
Enter lower and upper integer limits: 5 9 \n
The sums of the squares from 25 to 81 is 255 \n
Enter next set of limits: 3 25 \n
The sums of the squares from 9 to 625 is 5520 \n
Enter next set of limits: 5 5 \n
Done \n
*/

#include <stdio.h>

int main() {
	int lower, upper;
	int sum;

	printf("Enter lower and upper integer limits: ");
	scanf("%d %d", &lower, &upper);
	while (upper > lower) {
		sum = 0;
		for (int i = lower; i <= upper; i++) {
			sum += i * i;
		}
		printf(
			"The sums of the squares from %d to %d is %d\n", lower * lower,
			upper * upper, sum);
		printf("Enter next set of limits: ");
		scanf("%d %d", &lower, &upper);
	}
	printf("Done\n");
	return 0;
}
