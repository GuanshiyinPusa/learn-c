#include <stdio.h>

int main(void) {

	int imate = 2;
	long shot = 53456;
	char grade = 'A';
	float log = 2.71828;
	printf("The odds against the %d were %ld to 1.\n", imate, shot);
	printf("A score of %f is not an %c grade.\n", log, grade);
}

/*
 * Output:
 * The odds against the 2 were 53456 to 1.
 * A score of 2.718280 is not an A grade.
 */
