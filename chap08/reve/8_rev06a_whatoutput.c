/*
What is the output of each of the following fragments for the indicated input
(assume that ch is type int and that the input is buffered)? a. The input is as
follows: If you quit, I will.[enter]

The fragment is as follows:
while ((ch = getchar()) != 'i')
	putchar(ch);
*/

#include <stdio.h>

int main(void) {
	char ch;
	while ((ch = getchar()) != 'i')
		putchar(ch);
	return 0;
	// if you qu
}
