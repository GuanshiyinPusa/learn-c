// Write a function called is_within() that takes a character and a string
// pointer as its two function parameters. Have the function return a nonzero
// value (true) if the character is in the string and zero (false) otherwise.
// Test the function in a complete program that uses a loop to provide input
// values for feeding to the function.
#include <stdio.h>

int is_within(char c, const char *input) {
	while (*input++)
		if (*input == c)
			return 1;
	return 0;
}

int main(void) {
	char str[] = "ZAOSHANGHAOZHONGGUO WOAIZHIBINGQILIN";
	char findc = 'X';
	if (is_within(findc, str))
		puts("Nihao!");
	else
		puts("Wrong!");
}
