/*
Write a program that reads in a line of input and then prints the line in
reverse order. You can store the input in an array of char; assume that the line
is no longer than 255 characters. Recall that you can use scanf() with the %c
specifier to read a character at a time from input and that the newline
character (\n) is generated when you press the Enter key.
*/

#include <stdio.h>
#define MAX 255

int main(void) {
	char input[MAX];
	int i = 0;
	printf("Enter a line of input: ");
	while (scanf("%c", &input[i]) == 1 && input[i] != '\n')
		i++;
	printf("The line in reverse order: ");
	for (i--; i >= 0; i--)
		printf("%c", input[i]);
	printf("\n");
	return 0;
}
