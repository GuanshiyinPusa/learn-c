// What would the following program do? (Assume it’s run in a command - line
// environment.)
// It would open, if possible, the file whose name is the first command-line
// argument, and it would display onscreen each digit character in the file.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// get filename from cmdline, open it, print all the natural numbers inside.
// use file digit
int main(int argc, char *argv[]) {
	int ch;
	FILE *fp;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if ((fp = fopen(argv[1], "r")) == NULL)
		exit(EXIT_FAILURE);
	while ((ch = getc(fp)) != EOF)
		if (isdigit(ch))
			putchar(ch);
	fclose(fp);
	return 0;
}