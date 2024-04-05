/*
Write a program that reads a single word into a character array and then prints
the word backward. Hint: Use strlen() (Chapter 4) to compute the index of the
last character in the array.
*/

#include <stdio.h>
#include <string.h>

int main(void) {

	char word[50];
	printf("Give me a word:");
	scanf("%s", word);
	for (int i = 0; i <= strlen(word); i++)
		printf("%c", word[strlen(word) - i]);
	return 0;
}
