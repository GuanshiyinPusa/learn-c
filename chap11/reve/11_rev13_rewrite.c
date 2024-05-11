// Rewrite Listing 11.21 using ctype.h functions so that the program recognizes
// a correct answer regardless of the user’s choice of uppercase or lowercase.
/* compare.c -- this will work */
#include <ctype.h>
#include <stdio.h>
#include <string.h> // declares strcmp()
#define ANSWER "grant"
#define SIZE 40
char *s_gets(char *st, int n);
char *s_to_lower(char *st);

int main(void) {
	char try[SIZE];
	puts("Who is buried in Grant's tomb?");
	s_gets(try, SIZE);
	while (strcmp(s_to_lower(try), ANSWER) !=
		   0) { // or while(strcmp(try, ANSWER))
		printf("%d", strcmp(try, ANSWER));
		puts("No, that's wrong. Try again.");
		s_gets(try, SIZE);
	}
	puts("That's right!");
	return 0;
}

char *s_to_lower(char *st) {
	char *ret_val = st;
	while (*st) {
		*st = tolower(*st);
		st++;
	}
	return ret_val;
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
