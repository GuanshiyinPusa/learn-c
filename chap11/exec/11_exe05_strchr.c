// Design and test a function that searches the string specified by the first
// function parameter for the first occurrence of a character specified by the
// second function parameter. Have the function return a pointer to the
// character if successful, and a null if the character is not found in the
// string. (This duplicates the way that the library strchr() function works.)
// Test the function in a complete program that uses a loop to provide input
// values for feeding to the function.
#include <stdio.h>
#include <string.h>

char *stgstrchr(const char *s, char c) {
	while (*s++)
		if (*s == c)
			return (char *)s;
	return NULL;
}

int main() {
	char str[100];
	char ch;
	char *result;

	while (1) {
		// Prompt the user to enter a string
		printf("Enter a string (or 'exit' to quit): ");
		fgets(str, sizeof(str), stdin);

		// Check if the user wants to quit
		if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't') {
			break;
		}

		// Remove newline character from the end of the string if present
		size_t len = strlen(str);
		if (str[len - 1] == '\n') {
			str[len - 1] = '\0';
		}

		// Prompt the user to enter a character to search for
		printf("Enter a character to search for: ");
		scanf(" %c", &ch);
		getchar(); // Consume the newline character left in the buffer

		// Call stgstrchr function to search for the character
		result = stgstrchr(str, ch);

		// Check the result and print the appropriate message
		if (result != NULL) {
			int index = result - str;
			printf("Character '%c' found at index %d.\n", ch, index);
		} else {
			printf("Character '%c' not found in the string.\n", ch);
		}
	}

	return 0;
}
