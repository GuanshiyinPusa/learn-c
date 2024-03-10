/* print_countries.c -- a program that prints a list of countries
 * function br() will print Brazil and Russia
 * function ic() will print India and China
 */
#include <stdio.h>

void br(void);
void ic(void);

int main(void) {
	// print Brazil, Russia, India, China
	br();
	printf(", ");
	ic();
	printf("\n");

	// print India, China
	ic();
	printf("\n");

	// print Brazil, Russia
	br();
	printf("\n");

	return 0;
}

void br(void) { printf("Brazil, Russia"); }

void ic(void) { printf("India, China"); }

/*
 * Output:
 * Brazil, Russia, India, China
 * India, China
 * Brazil, Russia
 */
