#include <stdio.h>

int main(void) {
	char ch = '\r';

	printf("%c\n", ch);
	printf("%d\n", ch);
	printf("%o\n", ch);
	printf("%x\n", ch);

	return 0;
}

/*
 * Output:
 *
 * 13
 * 13
 * d
 */
