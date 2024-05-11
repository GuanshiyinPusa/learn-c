#include <stdio.h>

int main() {
	FILE *fp;
	char line[100];

	fp = fopen("filename.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s", line);
	}

	fclose(fp);
	return 0;
}