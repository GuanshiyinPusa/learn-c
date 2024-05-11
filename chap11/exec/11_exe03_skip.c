// Design and test a function that reads the first word from a line of input
// into an array and discards the rest of the line. It should skip over leading
// whitespace. Define a word as a sequence of characters with no blanks, tabs,
// or newlines in it. Use getchar(), not

#include <stdio.h>

char *fetch_n_chars(char *str) {
	int i = 0;
	char c;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			continue;
		str[i++] = c;
	}
	printf("i = %d\n", i);
	str[i] = '\0';
	return str;
}

int main() {
	char str[10];
	fetch_n_chars(str);
	puts(str);
	return 0;
}
