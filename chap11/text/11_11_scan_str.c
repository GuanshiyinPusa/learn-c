/* scan_str.c -- using scanf() */
#include <stdio.h>

int main(void) {
	char name1[11], name2[11];
	int count;

	printf("Please enter 2 names.\n");
	count = scanf("%5s %10s", name1, name2);
	printf("I read the %d name %s and %s.\n", count, name1, name2);

	return 0;
}

// Output:
// Please enter 2 names.
// Jesse Jukes
// I read the 2 names Jesse and Jukes.
// Please enter 2 names.
// Liza Applebottham
// I read the 2 names Liza and Applebotth.
// Please enter 2 names.
// Portensia Callowit
// I read the 2 names Porte and nsia.
