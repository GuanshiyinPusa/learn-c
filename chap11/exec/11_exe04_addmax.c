// Design and test a function like that described in Programming Exercise 3
// except that it accepts a second parameter specifying the maximum number of
// characters that can be read.

#include <stdio.h>

char *fetch_n_chars(char *str, int n) {
	int i = 0;
	char c;
	while (i < n && (c = getchar()) != EOF) {
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
	fetch_n_chars(str, 9);
	puts(str);
	return 0;
}
