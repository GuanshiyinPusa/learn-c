// Design a function that takes a string pointer as an argument and returns a
// pointer to the first space character in the string on or after the pointed-to
// position. Have it return a null pointer if it finds no spaces.

#include <stdio.h> /* for NULL definition */

char *strblk(const char *string) {
	while (*string != ' ' && *string != '\0') /* stops at first blank or null */
		string++;
	if (*string == '\0')
		return NULL; /* NULL is the null pointer */
	else
		return (char *)string;
}
