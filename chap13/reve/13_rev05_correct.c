// Write a program that takes two command-line arguments. The first is a
// character, and the second is a filename. The program should print only those
// lines in the file containing the given character.
#include <stdio.h>
#include <stdlib.h>
#define BUF 256
int has_ch(char ch, const char *line);
int has_ch1(char ch, const char *line);

int main(int argc, char *argv[]) {
	FILE *fp;
	char ch;
	char line[BUF];
	if (argc != 3) {
		printf("Usage: %s character filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ch = argv[1][0];
	if ((fp = fopen(argv[2], "r")) == NULL) {
		printf("Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, BUF, fp) != NULL) {
		if (has_ch(ch, line))
			fputs(line, stdout);
	}
	fclose(fp);
	return 0;
}

int has_ch(char ch, const char *line) {
	while (*line)
		if (ch == *line++)
			return (1);
	return 0;
}

int has_ch1(char ch, const char *line) {
	while (*line)
		return (ch == *line++);
	return 0;
}
