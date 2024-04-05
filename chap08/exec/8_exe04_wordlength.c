/*
Write a program that reads input as a stream of characters until encountering
EOF. Have it report the average number of letters per word. Don’t count
whitespace as being letters in a word. Actually, punctuation shouldn’t be
counted either, but don’t worry about that now. (If you do want to worry about
it, consider using the ispunct() function from the ctype.h family.)
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
	char ch;
	int length_word = 0;
	int word_counter = 0;
	int total_alpha = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\n' || ch == '\t' || ispunct(ch)) {
			total_alpha += length_word;
			word_counter++;
			length_word = 0;
		} else if (isalpha(ch)) {
			length_word++;
		} else {
			continue;
		}
	}
	printf("\nAverage number of letters per word: %.2f\n",
		   (float)total_alpha / word_counter);
}
