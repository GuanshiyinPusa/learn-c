
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_STRING_LENGTH 100

/* s_gets */
/**
 * @brief Read a line from stdin and replace '\n' with '\0'
 *
 * @param st
 * @param n
 * @return char*
 */

// Using array notation
char *s_gets(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	int i = 0;
	if (ret_val) // i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

// Using pointer notation
char *s_gets1(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) // i.e., ret_val != NULL
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

// Using strchr()
char *s_gets2(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) {
		char *newline = strchr(ret_val, '\n'); // find the first '\n's address
		if (newline)
			*newline = '\0';
		else {
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF)
				continue;
		}
	}
	return ret_val;
}

/**
 * @brief Copy the first n characters from a string
 *
 * @param input
 * @param n
 * @return char*
 */
char *copy_first_n(const char *input, int n) {
	int ct = 0;
	char *res;
	const char *end = input + n;
	while (*input && input < end) {
		res[ct++] = *input++;
	}
	res[ct] = '\0';
	return res;
}

/**
 * @brief Fit a string to a given size
 *
 * @param string
 * @param size
 */
void fit(char *string, unsigned int size) {
	if (strlen(string) > size)
		string[size] = '\0';
}

/**
 * @brief Swap two strings
 *
 * @param a
 * @param b
 */
void swap(char *a, char *b) {
	char temp[MAX_STRING_LENGTH];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

/**
 * @brief Print a string in reverse
 *
 * @param s
 */
void print_reverse(const char *s) {
	if (*s) {
		print_reverse(s + 1);
		putchar(*s);
	}
}

/**
 * @brief Print a string in an array
 *
 * @param string array
 */
void print_string_array(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings; i++) {
		printf("%s", strings[i]);
	}
}

/**
 * @brief Rank strings in an array in ASCII order
 *
 * @param num_strings
 * @param strings
 */
void rank_strings_ascii(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings - 1; i++)
		for (int j = 0; j < num_strings - i - 1; j++)
			if (strcmp(strings[j], strings[j + 1]) > 0)
				swap(strings[j], strings[j + 1]);
}

/**
 * @brief Rank strings in an array by length
 *
 * @param num_strings
 * @param strings
 */
void rank_strings_length(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings - 1; i++)
		for (int j = 0; j < num_strings - i - 1; j++)
			if (strlen(strings[j]) > strlen(strings[j + 1]))
				swap(strings[j], strings[j + 1]);
}

/**
 * @brief Get the length of the first word in a string
 *
 * @param str
 * @return int
 */
int get_first_word_length(const char *str) {
	int length = 0;
	while (*str++ && !isspace(*str)) {
		length++;
	}
	return length;
}

/**
 * @brief Rank strings in an array by the length of the first word
 *
 * @param num_strings
 * @param strings
 */
void rank_strings_first_word_length(
	int num_strings, char strings[MAX_STRINGS][MAX_STRING_LENGTH]) {
	for (int i = 0; i < num_strings - 1; i++)
		for (int j = 0; j < num_strings - i - 1; j++)
			if (get_first_word_length(strings[j]) >
				get_first_word_length(strings[j + 1]))
				swap(strings[j], strings[j + 1]);
}

/**
 * @brief Count the number of words in a string
 *
 * @param str
 * @return int
 */
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

/**
 * @brief Count the number of uppercase letters in a string
 *
 * @param str
 * @return int
 */
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

/**
 * @brief Count the number of lowercase letters in a string
 *
 * @param str
 * @return int
 */
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

/**
 * @brief Count the number of punctuation marks in a string
 *
 * @param str
 * @return int
 */
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

/**
 * @brief Count the number of digits in a string
 *
 * @param str
 * @return int
 */
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
