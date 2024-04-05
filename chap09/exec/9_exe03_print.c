/* Write a function that takes three arguments: a character and two integers.
The character is to be printed. The first integer specifies the number of times
that the character is to be printed on a line, and the second integer specifies
the number of lines that are to be printed. Write a program that makes use of
this function.*/
#include <stdio.h>
void print_letters(char, int, int);

void print_letters(char ch, int num_inline, int line) {
	for (int i = 0; i < line; i++) {
		for (int i = 0; i < num_inline; i++) {
			printf("%c", ch);
		}
		printf("\n");
	}
}

int main(void) { print_letters('x', 3, 5); }
