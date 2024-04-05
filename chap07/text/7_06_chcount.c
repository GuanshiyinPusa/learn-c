// chcount.c -- use the logical AND operator
#include <stdio.h>
#define PERIOD '.'

int main(void) {
	char ch;
	int charcount = 0;
	while ((ch = getchar()) != PERIOD) {
		if (ch != '"' && ch != '\'')
			charcount++;
	}
	printf("There are %d non-quote characters.\n", charcount);
	return 0;
}

// Output:
// "I count everything except quotes.".
// There are 29 non-quote characters.
// Program ended with exit code: 0
