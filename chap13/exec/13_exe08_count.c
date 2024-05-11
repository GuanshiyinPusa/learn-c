// Write a program that takes as command-line arguments a character and zero or
// more filenames. If no arguments follow the character, have the program read
// the standard input. Otherwise, have it open each file in turn and report how
// many times the character appears in each file. The filename and the character
// itself should be reported along with the count. Include error-checking to see
// whether the number of arguments is correct and whether the files can be
// opened. If a file can’t be opened, have the program report that fact and go
// on to the next file.
// ./a.out a 13_exe09_modify2.c 13_exe08_count.c
// 'a' appears 24 times in file 13_exe09_modify2.c
// 'a' appears 69 times in file 13_exe08_count.c
#include <stdio.h>
#include <stdlib.h>

int count_char_in_file(char c, FILE *file) {
	int count = 0;
	char ch;

	while ((ch = fgetc(file)) != EOF) {
		if (ch == c) {
			count++;
		}
	}

	return count;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s char [file ...]\n", argv[0]);
		return 1;
	}

	char c = argv[1][0];

	if (argc == 2) {
		int count = count_char_in_file(c, stdin);
		printf("'%c' appears %d times in stdin\n", c, count);
	} else {
		for (int i = 2; i < argc; i++) {
			FILE *file = fopen(argv[i], "r");
			if (file == NULL) {
				fprintf(stderr, "Failed to open file: %s\n", argv[i]);
				continue;
			}

			int count = count_char_in_file(c, file);
			printf("'%c' appears %d times in file %s\n", c, count, argv[i]);

			fclose(file);
		}
	}

	return 0;
}