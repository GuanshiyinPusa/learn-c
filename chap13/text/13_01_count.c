/* count.c -- using standard I/O */
#include <stdio.h>
#include <stdlib.h> // exit() prototype

int main(int argc, char *argv[]) {
	int ch;	  // place to store each character as read
	FILE *fp; // "file pointer"
	unsigned long count = 0;
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF) { // getc needs a source compares to getchar
		putc(ch, stdout);			 // same as putchar(ch);
		count++;
	}
	fclose(fp); // if close successfully, fclose() return 0
	// if (fclose(fp) != 0)
	// 	printf("Error in closing file %s\n", argv[1]);
	printf("File %s has %lu characters\n", argv[1], count);
	return 0; // note: same as exit(0) == exit(EXIT_SUCCESS)
}