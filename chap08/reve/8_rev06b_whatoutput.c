/*
What is the output of each of the following fragments for the indicated input
(assume that ch is type int and that the input is buffered)? b. The input is as
follows: Harhar[enter]

The fragment is as follows:
while ((ch = getchar()) != '\n')
{
	putchar(ch++);
	putchar(++ch);
}
*/

#include <stdio.h>

int main(void) {
	char ch;
	while ((ch = getchar()) != '\n') {
		putchar(ch++);
		putchar(++ch);
	}
	return 0;
}
