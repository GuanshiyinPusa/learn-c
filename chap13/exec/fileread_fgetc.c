#include <stdio.h>

int main() {
	FILE *fp;
	int ch;

	fp = fopen("filename.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	while ((ch = fgetc(fp)) != EOF) {
		putchar(ch);
	}

	fclose(fp);
	return 0;
}