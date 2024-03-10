/* Construct a printf() statement that uses BOOK, cost, and percent to print the
following: This copy of "War and Peace" sells for $12.99.
That is 80% of list. */
#include <stdio.h>
#define BOOK "War and Peace"

int main(void) {
	float cost = 12.99;
	float percent = 80.0;

	printf("This copy of \"%s\" sells for $%0.2f. That is %0.0f%% of list.\n",
		   BOOK, cost, percent);

	return 0;
}
