/*
Write a program that requests your first name and does the following with it:
a. Prints it enclosed in double quotation marks
b. Prints it in a field 20 characters wide, with the whole field in quotes and
the name at the right end of the fieldProgramming Exercises c. Prints it at the
left end of a field 20 characters wide, with the whole field enclosed in quotes
d. Prints it in a field three characters wider than the name
*/

#include <stdio.h>
#include <string.h>
int main(void) {
	char first[40];

	printf("Please enter your first name:\n");
	scanf("%s", first);
	printf("\"%s\"\n", first);
	printf("\"%20s\"\n", first);
	printf("\"%-20s\"\n", first);
	printf("%*s\n", (int)strlen(first) + 3, first);

	return 0;
}

// Output:
// Please enter your first name:
// Shuyuan
// "Shuyuan"
// "             Shuyuan"
// "Shuyuan             "
//   Shuyuan
