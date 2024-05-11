// The s_gets() function defined in this chapter can be written using strchr()
// instead of a while loop to find the newline. Do so.

#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n) {
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
