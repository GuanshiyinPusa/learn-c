#include <stdio.h>
#define STLEN 10

// fgets keep '\n'
// gets unsafe
// gets_s read until n-1 characters are read, '\n' is encountered, or EOF, then
// appends '\0' to the end of input string. If the input length exceeds n-1, it
// will only reads in n-1
// s_gets read whole line and use '\0' to replace '\n' and store it in st.
// If the input length exceeds n-1, it will only reads in n-1
// return NULL if EOF is encountered, otherwise return the input string
char *s_gets(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	int i = 0;
	if (ret_val) // i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

int main(void) {
	char words[STLEN];
	char *what;
	puts("Enter strings (empty line to quit):");
	while ((what = s_gets(words, STLEN)) != NULL && words[0] != '\0')
		printf("what: %s\n", what);
	puts("done");

	return 0;
}

// Output:
// Enter strings (empty line to quit):
// This
// This
// program seems
// program s
// unwilling to accept long lines.
// unwilling
// But it doesn't get stuck on long
// But it do
// lines either.
// lines eit
// done
