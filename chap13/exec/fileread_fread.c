#include <stdio.h>

int main() {
	FILE *fp;
	char buffer[1024];
	size_t bytesRead;

	fp = fopen("filename.txt", "rb");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	while ((bytesRead = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
		fwrite(buffer, 1, bytesRead, stdout);
	}

	fclose(fp);
	return 0;
}