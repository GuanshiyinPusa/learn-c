// Write a program that opens two files. You can obtain the filenames either by
// using command-line arguments or by soliciting the user to enter them.
// a. Have the program print line 1 of the first file, line 1 of the second
// file, line 2 of the first file, line 2 of the second file, and so on, until
// the last line of the longer file (in terms of lines) is printed.
// b. Modify the program so that lines with the same line number are printed on
// the same line.
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: %s <file1> <file2>\n", argv[0]);
		return 1;
	}

	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");

	if (file1 == NULL || file2 == NULL) {
		printf("Error opening files.\n");
		return 1;
	}

	char line1[256], line2[256];
	while (!feof(file1) || !feof(file2)) {
		if (fgets(line1, sizeof(line1), file1)) {
			printf("%s", line1);
		}
		if (fgets(line2, sizeof(line2), file2)) {
			printf("%s", line2);
		}
	}

	fclose(file1);
	fclose(file2);

	return 0;
}