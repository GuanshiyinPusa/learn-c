/* Write a program that asks for your first name, your last name, and then
prints the names in the format last, first. */
#include <stdio.h>

int main(void) {
	char first[40];
	char last[40];

	printf("Please enter your first name:\n");
	scanf("%s", first);
	printf("Please enter your last name:\n");
	scanf("%s", last);
	printf("%s, %s\n", last, first);

	return 0;
}

// Output:
// Please enter your first name:
// Shuyuan
// Please enter your last name:
// Gao
// Gao, Shuyuan
