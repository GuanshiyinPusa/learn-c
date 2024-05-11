// Write a program that reads in up to 10 strings or to EOF, whichever comes
// first. Have it offer the user a menu with five choices:
// print the original list of strings,
// print the strings in ASCII collating sequence,
// print the strings in order of increasing length,
// print the strings in order of the length of the first word in the string,
// and quit.
// Have the menu recycle until the user enters the quit request. The program, of
// course, should actually perform the promised tasks.

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 10
#define MAX_STRING_LENGTH 100

void print_string_array(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]);
void rank_strings_ascii(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]);
void rank_strings_length(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]);
void rank_strings_first_word_length(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]);
int get_first_word_length(const char *str);
void swap(char *a, char *b);

int main() {
	char strings[MAX_STRINGS][MAX_STRING_LENGTH];
	int num_strings = 0;
	char choice;

	// Read in up to 10 strings or until EOF
	while (num_strings < MAX_STRINGS &&
		   fgets(strings[num_strings], MAX_STRING_LENGTH, stdin) != NULL) {
		num_strings++;
	}

	// Display the menu and handle user choices
	while (1) {
		printf("\nHere are the options:\n");
		printf("A: Print the original list of strings.\n");
		printf("B: Print the strings in ASCII collating sequence.\n");
		printf("C: Print the strings in order of increasing length.\n");
		printf("D: Print the strings in order of the length of the first word "
			   "in the string.\n");
		printf("E: Quit.\n");

		choice = getchar();
		getchar(); // Consume the newline character

		switch (choice) {
		case 'A':
			print_string_array(num_strings, strings);
			break;
		case 'B':
			rank_strings_ascii(num_strings, strings);
			print_string_array(num_strings, strings);
			break;
		case 'C':
			rank_strings_length(num_strings, strings);
			print_string_array(num_strings, strings);
			break;
		case 'D':
			rank_strings_first_word_length(num_strings, strings);
			print_string_array(num_strings, strings);
			break;
		case 'E':
			return 0;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	}
}

void print_string_array(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings; i++) {
		printf("%s", strings[i]);
	}
}

void rank_strings_ascii(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings - 1; i++)
		for (int j = 0; j < num_strings - i - 1; j++)
			if (strcmp(strings[j], strings[j + 1]) > 0)
				swap(strings[j], strings[j + 1]);
}

void rank_strings_length(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings - 1; i++)
		for (int j = 0; j < num_strings - i - 1; j++)
			if (strlen(strings[j]) > strlen(strings[j + 1]))
				swap(strings[j], strings[j + 1]);
}

void rank_strings_first_word_length(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings - 1; i++)
		for (int j = 0; j < num_strings - i - 1; j++)
			if (get_first_word_length(strings[j]) >
				get_first_word_length(strings[j + 1]))
				swap(strings[j], strings[j + 1]);
}

int get_first_word_length(const char *str) {
	int length = 0;
	while (*str++ && !isspace(*str)) {
		length++;
	}
	return length;
}

void swap(char *a, char *b) {
	char temp[MAX_STRING_LENGTH];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}
