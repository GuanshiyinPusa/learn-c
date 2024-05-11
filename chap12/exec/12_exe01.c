/* global.c -- uses an external variable */
#include <stdio.h>
int critic(int units);

int main(void) {
	int units = 0; /* an optional redeclaration */
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
		units = critic(units);
	printf("You must have looked it up!\n");
	return 0;
}

int critic(int units) {
	/* optional redeclaration omitted */
	printf("No luck, my friend. Try again.\n");
	scanf("%d", &units);
	return units;
}

// Output:
// How many pounds to a firkin of butter?
// 14
// No luck, my friend. Try again.
// 56
// You must have looked it up!
