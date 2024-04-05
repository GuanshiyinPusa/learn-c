/*
Write a program that creates an array with 26 elements and stores the 26
lowercase letters in it. Also have it show the array contents.
*/

#include <stdio.h>

int main(void) {
	char letter[27]; // letter a's ascii is 97, z's ascii is 122

	for (int i = 97; i < 123; i++) {
		letter[i - 97] = i;
		printf("%c", letter[i - 97]);
	}
	letter[26] = '\0';
	printf("\n%s\n", letter);
	return 0;
}
