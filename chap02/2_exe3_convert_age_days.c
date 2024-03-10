/* convert_age_days.c -- convert my age to days without considering leap year */
#include <stdio.h>

int main(void) {
	int age;
	int age_in_days;

	age = 21;
	age_in_days = age * 365;

	printf("%d days is how long I have lived.\n", age_in_days);

	return 0;
}

/*
 * Output:
 * 7665 days is how long I have lived.
 */
