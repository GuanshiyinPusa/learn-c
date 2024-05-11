/* put1.c -- prints a string without adding \n */
#include <stdio.h>

void puts1(const char *string) /* string not altered */
{
	while (*string != '\0') // while (*string) also works
		putchar(*string++);
}
