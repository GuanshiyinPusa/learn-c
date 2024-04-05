#include <stdio.h>

int main(void) {
	char ch;
	do {
		scanf("%c", &ch);
		printf("%c", ch);
	} while (ch != 'g');
	return 0;
}

// Input:
// Go west, young man!
// Output:
// Go west, young
