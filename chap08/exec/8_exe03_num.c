/*
Write a program that reads input as a stream of characters until encountering
EOF. Have it report the number of uppercase letters, the number of lowercase
letters, and the number of other characters in the input. You may assume that
the numeric values for the lowercase letters are sequential and assume the same
for uppercase. Or, more portably, you can use appropriate classification
functions from the ctype.h library.
*/
#include <ctype.h>
#include <stdio.h>

int main(void) {
	char ch;
	int num_upper = 0;
	int num_lower = 0;
	int num_other = 0;
	while ((ch = getchar()) != EOF) {
		if isupper (ch)
			num_upper++;
		else if islower (ch)
			num_lower++;
		else
			num_other++;
	}
	printf("\nNumber of uppercase letters: %d\n", num_upper);
	printf("Number of lowercase letters: %d\n", num_lower);
	printf("Number of other characters: %d\n", num_other);
}
