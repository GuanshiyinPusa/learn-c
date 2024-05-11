#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file_pointer;
	char buffer[100];

	// Open a file for reading
	file_pointer = fopen("example.txt", "r");
	if (file_pointer == NULL) {
		perror("Error opening the file");
		return 1;
	}

	// Read data from the file until EOF is reached
	while (!feof(file_pointer)) {
		if (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
			printf("%s", buffer);
		}
	}

	// Check for read error
	if (ferror(file_pointer)) {
		printf("Error reading from the file.\n");
	}

	// Close the file
	fclose(file_pointer);

	return 0;
}
