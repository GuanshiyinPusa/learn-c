#include <stdio.h>
#define ASCII_a 97
#define ASCII_g 103
int main(void) {
	int n = ASCII_a - 1;
	while ((n++) < ASCII_g)
		printf("%c", n);
	printf("\n");
	return 0;
}

// Output:
// abcdefg
