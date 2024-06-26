/*
Write a program that asks the user to enter the number of days and then converts
that value to weeks and days. For example, it would convert 18 days to 2 weeks,
4 days. Display results in the following format: 18 days are 2 weeks, 4 days.
Use a while loop to allow the user to repeatedly enter day values; terminate the
loop when the user enters a nonpositive value, such as 0 or -20.
*/
#include <stdio.h>
#define DAYS_IN_WEEK 7

int main(void) {
	int days, weeks, left;
	printf("This program converts days to weeks and ");
	printf("days.\n");
	printf("Just enter the number of days.\n");
	printf("Enter 0 to end the program.\n");
	scanf("%d", &days);
	while (days > 0) {
		weeks = days / DAYS_IN_WEEK;
		left = days % DAYS_IN_WEEK;
		printf("%d days are %d weeks, %d days. \n", days, weeks, left);
		printf("Next input?\n");
		scanf("%d", &days);
	}
	printf("Bye!\n");
	return 0;
}

// Output:
// This program converts days to weeks and days.
// Just enter the number of days.
// Enter 0 to end the program.
// 13
// 13 days are 1 weeks, 6 days.
// Next input?
// 0
// Bye!
