#include <stdio.h>

int main(void) {
	char ch;
	scanf("%c", &ch);
	for (ch = '$'; ch != 'g'; scanf("%c", &ch))
		printf("%c", ch);
	return 0;
}

// Input:
// Go west, young man!
// Output:
// $o west, youn
