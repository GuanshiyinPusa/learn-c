// Write a function that replaces the contents of a string with the string
// reversed. Test the function in a complete program that uses a loop to provide
// input values for feeding to the function.
#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
	int len = strlen(str);
	char temp;
	for (int i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main(void) {
	char str[] = "Hello, World!";
	reverse_string(str);
	printf("Reversed string: %s\n", str);
}
