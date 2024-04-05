/*
Write a program that reads input up to # and reports the number of times that
the sequence ei occurs.
*/

#include <stdio.h>

int main(void) {
	char c;
	int n_ei = 0;
	while ((c = getchar()) != '#') {
		if (c == 'e') {
			c = getchar();
			if (c == 'i')
				n_ei++;
		}
	}
	printf("number of times that the sequence ei occurs: %d\n", n_ei);
	return 0;
}
