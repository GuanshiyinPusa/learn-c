// Modify and test the function in exercise 1 so that it stops after n
// characters or after the first blank, tab, or newline, whichever comes first.
// (Don’t just use scanf().)

#include <stdio.h>

char *fetch_n_chars(char *str, int n) {
	int i = 0;
	char c;
	while (i < n && (c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
			break;
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
