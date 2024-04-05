/*
Devise a program that counts the number of characters in its input up to the end
of file.
*/
#include <stdio.h>

int main(void) {
	int num_char = 0;
	while (getchar() != EOF)
		num_char++;
	printf("Number of characters: %d\n", num_char);
}
