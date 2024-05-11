// strings1.c
#include <stdio.h>
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81

int main(void) {
	char words[MAXLENGTH] = "I am a string in an array.";
	const char *pt1 = "something is pointing at me.";
	puts("There are some strings:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);

	return 0;
}

// Output:
//  There are some strings:
//  I am a symbolic string constant.
//  I am a string in an array.
//  something is pointing at me.
//  I am a spring in an array.
