/*
Write a program that converts time in minutes to time in hours and minutes. Use
#define or const to create a symbolic constant for 60. Use a while loop to allow
the user to enter values repeatedly and terminate the loop if a value for the
time of 0 or less is entered.
*/
#include <stdio.h>
#define MINUTES_IN_HOUR 60

int main(void) {
	int minutes, hours, left;
	printf("This program converts minutes to hours and ");
	printf("minutes.\n");
	printf("Just enter the number of minutes.\n");
	printf("Enter 0 to end the program.\n");
	scanf("%d", &minutes);
	while (minutes > 0) {
		hours = minutes / MINUTES_IN_HOUR;
		left = minutes % MINUTES_IN_HOUR;
		printf("%d minutes is %d hours, %d minutes. \n", minutes, hours, left);
		printf("Next input?\n");
		scanf("%d", &minutes);
	}
	printf("Bye!\n");
	return 0;
}

// Output:
/*
This program converts minutes to hours and minutes.
Just enter the number of minutes.
Enter 0 to end the program.
120
120 minutes is 2 hours, 0 minutes.
Next input?
670
670 minutes is 11 hours, 10 minutes.
Next input?
0
Bye!
*/
