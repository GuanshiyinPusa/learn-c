#include <stdio.h>
#include <string.h>

// fgets keep '\n'
// gets unsafe
// gets_s read until n-1 characters are read, '\n' is encountered, or EOF, then
// appends '\0' to the end of input string. If the input length exceeds n-1, it
// will only reads in n-1
// s_gets read whole line and use '\0' to replace '\n' and store it in st.
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
