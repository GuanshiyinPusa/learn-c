#include <stdio.h>

int main(void) {
	int i, j, list[10];
	// int i, j, list(10);
	// for (i = 1, i <= 10, i++) {
	for (i = 0; i < 10; i++) {
		list[i] = 2 * i + 3; // list = 5 7 9 11 13 15 17 19 21 23
		// for (j = 1, j > = i, j++)
		for (j = 0; j <= i; j++)
			printf(" %d", list[j]);
		printf("\n");
	}
	return 0;
}
