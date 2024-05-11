// Write a program that sequentially displays onscreen all the files listed in
// the command line. Use argc to control a loop.

#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int main(int argc, char *argv[]) {
	FILE *fp;
	char line[LEN];
	int ch;
	if (argc < 2) {
		printf("Usage: %s character filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			printf("Error opening file %s\n", argv[i]);
			continue;
		}
		while ((ch = fgetc(fp)) !=
			   EOF)			  // getc needs a source compares to getchar
			putc(ch, stdout); // same as putchar(ch);
		fclose(fp);
	}
}