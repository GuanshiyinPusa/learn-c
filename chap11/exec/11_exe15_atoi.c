// Use the character classification functions to prepare an implementation of
// atoi(); have this version return the value of 0 if the input string is not a
// pure number.

#include <ctype.h>

int new_atoi(const char *str) {
	int result = 0;
	while (*str) {
		if (isdigit(*str)) {
			result = result * 10 + (*str - '0');
		} else {
			return 0;
		}
		str++;
	}
	return result;
}
