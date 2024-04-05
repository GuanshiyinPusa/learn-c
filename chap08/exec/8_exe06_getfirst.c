/*
Modify the get_first() function of Listing 8.8 so that it returns the first non-
whitespace character encountered. Test it in a simple program.
*/
#include <stdio.h>

char get_first(void) {
	int ch;
	ch = getchar();
	while (getchar() != ' ')
		continue;
	return ch;
}

int main(void) {
	char ch;
	ch = get_first();
	printf("First non-whitespace character: %c\n", ch);
	return 0;
}
