/* nested_loop.c */
#include <stdio.h>

int main(void) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 7; j++) {
			printf("$");
		}
		printf("\n");
	}
	return 0;
}

// Output:
// $$$$$$$
// $$$$$$$
// $$$$$$$
// $$$$$$$
