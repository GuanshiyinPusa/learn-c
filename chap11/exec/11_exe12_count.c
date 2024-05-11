// Write a program that reads input up to EOF and reports the number of words,
// the number of uppercase letters, the number of lowercase letters, the number
// of punctuation characters, and the number of digits. Use the ctype.h family
// of functions.

#include <ctype.h>
#include <stdio.h>
int count_words(const char *str);
int count_uppercase(const char *str);
int count_lowercase(const char *str);
int count_punctuation(const char *str);
int count_digits(const char *str);

int main(void) {
	char str[100];
	fgets(str, 100, stdin);
	printf("Number of words: %d\n", count_words(str));
	printf("Number of uppercase letters: %d\n", count_uppercase(str));
	printf("Number of lowercase letters: %d\n", count_lowercase(str));
	printf("Number of punctuation characters: %d\n", count_punctuation(str));
	printf("Number of digits: %d\n", count_digits(str));

	return 0;
}

int count_words(const char *str) {
	int count = 0;
	int in_word = 0;
	while (*str) {
		if (isspace(*str)) {
			in_word = 0;
		} else if (!in_word) {
			in_word = 1;
			count++;
		}
		str++;
	}
	return count;
}

int count_uppercase(const char *str) {
	int count = 0;
	while (*str) {
		if (isupper(*str)) {
			count++;
		}
		str++;
	}
	return count;
}

int count_lowercase(const char *str) {
	int count = 0;
	while (*str) {
		if (islower(*str)) {
			count++;
		}
		str++;
	}
	return count;
}

int count_punctuation(const char *str) {
	int count = 0;
	while (*str) {
		if (ispunct(*str)) {
			count++;
		}
		str++;
	}
	return count;
}

int count_digits(const char *str) {
	int count = 0;
	while (*str) {
		if (isdigit(*str)) {
			count++;
		}
		str++;
	}
	return count;
}
