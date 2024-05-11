// The ANSI C library has more than 20 string-handling functions, and the
// following list summa- rizes some of the more commonly used ones:

char *strcpy(char *restrict s1, const char *restrict s2);
// This function copies the string (including the null character) pointed to by
// s2 to the location pointed to by s1. The return value is s1.

char *strncpy(char *restrict s1, const char *restrict s2, size_t n);
// This function copies to the location pointed to by s1 no more than n
// characters from the string pointed to by s2. The return value is s1. No
// characters after a null character are copied and, if the source string is
// shorter than n characters, the target string is padded with null characters.
// If the source string has n or more characters, no null character is copied.
// The return value is s1.

char *strcat(char *restrict s1, const char *restrict s2);
// The string pointed to by s2 is copied to the end of the string pointed to by
// s1. The first character of the s2 string is copied over the null character of
// the s1 string. The return value is s1.

char *strncat(char *restrict s1, const char *restrict s2, size_t n);
// No more than the first n characters of the s2 string are appended to the s1
// string, with the first character of the s2 string being copied over the null
// character of the s1 string. The null character and any characters following
// it in the s2 string are not copied, and a null character is appended to the
// result. The return value is s1.

int strcmp(const char *s1, const char *s2);
// This function returns a positive value if the s1 string follows the s2 string
// in the machine collating sequence, the value 0 if the two strings are
// identical, and a negative value if the first string precedes the second
// string in the machine collating sequence.

int strncmp(const char *s1, const char *s2, size_t n);
// This function works like strcmp(), except that the comparison stops after n
// characters or when the first null character is encountered, whichever comes
// first.

char *strchr(const char *s, int c);
// This function returns a pointer to the first location in the string s that
// holds the character c. (The terminating null character is part of the string,
// so it can be searched for.) The function returns the null pointer if the
// character is not found.

char *strpbrk(const char *s1, const char *s2);
// This function returns a pointer to the first location in the string s1 that
// holds any character found in the s2 string. The function returns the null
// pointer if no character is found.

char *strrchr(const char *s, int c);
// This function returns a pointer to the last occurrence of the character c in
// the string s. (The terminating null character is part of the string, so it
// can be searched for.) The function returns the null pointer if the character
// is not found.

char *strstr(const char *s1, const char *s2);
// This function returns a pointer to the first occurrence of string s2 in
// string s1. The function returns the null pointer if the string is not found.

size_t strlen(const char *s);
// This function returns the number of characters, not including the terminating
// null character, found in the string s.
