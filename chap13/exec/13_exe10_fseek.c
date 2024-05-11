// Write a program that opens a text file whose name is obtained interactively.
// Set up a loop that asks the user to enter a file position. The program then
// should print the part of the file starting at that position and proceed to
// the next newline character. Let negative or nonnumeric input terminate the
// user-input loop.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void) {
	char filename[MAX];
	FILE *fp;
	long pos;
	int ch;

	printf("Enter the filename: ");
	scanf("%s", filename);

	// Open File Error Checking
	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("Enter a file position (negative or nonnumeric to quit): ");
	while (scanf("%ld", &pos) == 1 && pos >= 0) {
		fseek(fp, pos, SEEK_SET);
		while ((ch = getc(fp)) != '\n' && ch != EOF)
			putchar(ch);
		putchar('\n');

		printf("Enter a file position (negative or nonnumeric to quit): ");
	}

	fclose(fp);
	return 0;
}