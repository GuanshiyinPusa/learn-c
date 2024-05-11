// Write a function called string_in() that takes two string pointers as
// arguments. If the second string is contained in the first string, have the
// function return the address at which the contained string begins. For
// instance, string_in("hats", "at") would return the address of the a in hats.
// Otherwise, have the function return the null pointer. Test the function in a
// complete program that uses a loop to provide input values for feeding to the
// function.
#include <stdio.h>

char *string_in(const char *str, const char *str2) {
	int i, j;
	for (i = 0; str[i]; i++) {
		for (j = 0; str2[j]; j++)
			if (str[i + j] == str2[j])
				break;
		if (str2[j])
			return (char *)str + i;
	}
	return NULL;
}
