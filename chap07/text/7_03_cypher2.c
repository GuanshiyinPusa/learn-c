// cypher2.c -- alters input, preserving non-letters
#include <ctype.h> // for isalpha()
#include <stdio.h>

int main(void) {
	char ch;
	while ((ch = getchar()) != '\n') {
		if (isalpha(ch))	 // if a letter,
			putchar(ch + 1); // display next letter
		else				 // otherwise,
			putchar(ch);	 // display as is
	}
	putchar(ch); // display the newline
	return 0;
}

// Output:
// Look! It's a programmer!
// Mppl! Ju't b qsphsbnnfs!
// Program ended with exit code: 0
