// arrchar.c -- array of pointers, array of strings
#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(void) {
	// array of five pointers, take 40 bytes.
	const char *mytalents[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately",
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language",
	};
	// array of 5 array, take 200 bytes.
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping",
		"Watching television",
		"Mailing letters",
		"Reading email",
	};
	int i;
	puts("Let's compare talents.");
	printf("%-36s %-25s\n", "My Talents", "Your Talents");
	for (i = 0; i < LIM; i++)
		printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
	printf(
		"\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents),
		sizeof(yourtalents));
	return 0;
}
// NOTE: The pointers in mytalents point to the locations of the string literals
// used for initialization, which are stored in static memory. The arrays in
// yourtalents, however, contain copies of the string literals, so each string
// is stored twice.

// Output:
// Let's compare talents.
// My Talents                           Your Talents
// Adding numbers swiftly               Walking in a straight line
// Multiplying accurately               Sleeping
// Stashing data                        Watching television
// Following instructions to the letter Mailing letters
// Understanding the C language         Reading email
//
// sizeof mytalents: 40, sizeof yourtalents: 200
