// The strlen() function takes a pointer to a string as an argument and returns
// the length of the string. Write your own version of this function.

int strlen2(char *st) {
	int ct = 0;
	while (*st++)
		ct++;
	return ct;
}
