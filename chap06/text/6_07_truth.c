// truth.c -- what values are true?
#include <stdio.h>

int main(void) {
	int n = 3;
	while (n)
		printf("%2d is true\n", n--);
	printf("%2d is false\n", n);
	n = -3;
	while (n)
		printf("%2d is true\n", n++);
	printf("%2d is false\n", n);
	return 0;
}

// Output:
// 3 is true
// 2 is true
// 1 is true
// 0 is false
// -3 is true
// -2 is true
// -1 is true
// 0 is false
