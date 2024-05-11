/* strcnt.c -- try strtol() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 30
char *s_gets(char *st, int n);
char *s_gets2(char *st, int n);

int main(void) {
	char number[LIM];
	char *end;
	long value;

	puts("Enter a number (empty line to quit):");
	while (s_gets2(number, LIM) && number[0] != '\0') {
		value = strtol(number, &end, 10);
		printf(
			"base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value,
			end, *end);
		value = strtol(number, &end, 16);
		printf(
			"base 16 input, base 10 output: %ld, stopped at %s (%d)\n", value,
			end, *end);
		puts("Next number:");
	}
	puts("Bye!");

	return 0;
}

char *s_gets(char *st, int n) {
	char *ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val) // i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0') {
			i++;
		}
		if (st[i] == '\n')
			st[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

char *s_gets2(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) {
		char *newline = strchr(ret_val, '\n'); // find the first '\n's address
		if (newline)
			*newline = '\0';
		else {
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF)
				continue;
		}
	}
	return ret_val;
}
