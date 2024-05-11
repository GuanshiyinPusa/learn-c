#include <stdio.h>

int main() {
	FILE *fp;
	char word[100];

	fp = fopen("filename.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (fscanf(fp, "%s", word) != EOF) {
		printf("%s ", word);
	}

	fclose(fp);
	return 0;
}