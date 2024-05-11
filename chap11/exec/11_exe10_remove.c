// Write a function that takes a string as an argument and removes the spaces
// from the string. Test it in a program that uses a loop to read lines until
// you enter an empty line. The program should apply the function to each input
// string and display the result.
#include <ctype.h>

void remove_whitespace(char *str) {
	int i, j;
	for (i = 0, j = 0; str[i]; i++) {
		if (!isspace(str[i])) {
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}
