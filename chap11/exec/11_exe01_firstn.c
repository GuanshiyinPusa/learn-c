// Design and test a function that fetches the next n characters from input
// (including blanks, tabs, and newlines), storing the results in an array whose
// address is passed as an argument.

#include <stdio.h>

char *fetch_n_chars(char *str, int n) {
	int i = 0;
	char c;
	while (i < n && (c = getchar()) != EOF) {
		str[i++] = c;
	}
	printf("i = %d\n", i);
	str[i] = '\0';
	return str;
}

int main() {
	char str[10];
	fetch_n_chars(str, 9);
	puts(str);
	return 0;
}
