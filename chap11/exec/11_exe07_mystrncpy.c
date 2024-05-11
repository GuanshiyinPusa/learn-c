// The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1,
// truncating s2 or padding it with extra null characters as necessary. The
// target string may not be null-terminated if the length of s2 is n or more.
// The function returns s1. Write your own version of this function; call it
// mystrncpy(). Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.
char *mystrncpy(char *des, const char *src, int n) {
	for (int i = 0; i < n; i++) {
		if (*src == '\0')
			*des++ =
				'\0'; // padding it with extra null characters as necessary.
		else
			*des++ = *src++;
	}
	return des;
}

char *mystrncpy2(char *s1, char *s2, int n) {
	int i = 0;
	while (i < n && s2[i] != '\0') {
		s1[i] = s2[i];
		i++;
	}
	while (i < n) {
		s1[i++] = '\0';
	}
	return s1;
}
