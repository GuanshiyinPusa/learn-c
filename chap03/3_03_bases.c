/* bases.c -- prints 100 in decimal, octal, and hex */
#include <stdio.h>

int main(void) {
	int x = 100;

	printf("dec = %d; octal = %o, hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o, hex = %#x\n", x, x, x);

	return 0;
}

/*
 * Output:
 * dec = 100; octal = 144, hex = 64
 * dec = 100; octal = 0144, hex = 0x64
 */
