// string.c
#include <stdio.h>
#define MSG "I am a symbolic string constant." // "string\0" is string literal
#define MAXLENGTH 81

int main(void) {
	char words[MAXLENGTH] = "I am a string in an array.";
	const char *pt1 = "Something is pointing at me.";
	puts("Here are some strings:"); // puts is like printf, but only prints
									// string, it puts newline at the end of the
									// string automatically
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);

	return 0;
}

// Output:
// Here are some strings:
// I am a symbolic string constant.
// I am a string in an array.
// Something is pointing at me.
// I am a spring in an array.
