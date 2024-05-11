// Modify the program in Listing 13.5 so that it uses a command-line interface
// instead of an interactive interface.
// ./a.out source destination
/* append.c -- appends files to a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *fa, *fs;
	int files = 0;
	int ch;

	if ((fa = fopen(argv[2], "a+")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	if (strcmp(argv[1], argv[2]) == 0)
		fputs("Can't append file to itself\n", stderr);
	else if ((fs = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	} else {
		if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
			fputs("Can't create input buffer\n", stderr);
			exit(EXIT_FAILURE);
		}
		append(fs, fa);
		if (ferror(fs) != 0)
			fprintf(stderr, "Error in reading file %s.\n", argv[1]);
		if (ferror(fa) != 0)
			fprintf(stderr, "Error in writing file %s.\n", argv[2]);
		fclose(fs);
		files++;
		printf("File %s appended.\n", argv[1]);
	}

	printf("Done appending. %d files appended.\n", files);
	rewind(fa);
	printf("%s contents:\n", argv[2]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);
	return 0;
}

void append(FILE *source, FILE *dest) {
	size_t bytes;
	static char temp[BUFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}