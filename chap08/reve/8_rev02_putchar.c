/*
What would each of the following statements accomplish?
a. putchar('H');
b. putchar('\007');
c. putchar('\n');
d. putchar('\b');
*/

#include <stdio.h>

int main(void) {
	putchar('H');	 // Prints H
	putchar('\007'); // Makes a beep sound
	putchar('\n');	 // Prints a newline
	putchar('\b');	 // Prints a backspace
}
