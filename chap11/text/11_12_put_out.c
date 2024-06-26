/* put_out.c -- using puts() */
#include <stdio.h>
#define DEF "I am a #defined string"

int main(void) {
	char str1[80] = "An array was initialized to me.";
	const char *str2 = "A pointer is initialized to me";
	puts("I'm an argument to puts()."); // adds '\n' at the end
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2 + 4);

	return 0;
}

// Output:
// I'm an argument to puts().
// I am a #defined string.
// An array was initialized to me.
// A pointer was initialized to me.
// ray was initialized to me.
// inter was initialized to me.
