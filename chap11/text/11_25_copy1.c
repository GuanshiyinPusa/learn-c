/* copy1.c -- strcpy() demo */
#include <stdio.h>
#include <string.h> // declares strcpy()
#define SIZE 40
#define LIM 5
char *s_gets(char *st, int n);

int main(void) {
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	printf("Enter %d words beginning with q:\n", LIM);
	while (i < LIM && s_gets(temp, SIZE)) {
		if (temp[0] != 'q') // can also use if(strncmp(temp,"q",1) != 0)
			printf("%s doesn't begin with q!\n", temp);
		else {
			strcpy(qwords[i], temp);
			i++;
		}
	}
	puts("Here are the words accepted:");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);
	return 0;
}

// read whole line and use '\0' to replace '\n'
char *s_gets(char *st, int n) {
	char *ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val) // i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0') {
			i++;
		}
		if (st[i] == '\n')
			st[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

// Output:
// Enter 5 words beginning with q:
// quackery
// quasar
// quilt
// quotient
// no more
// no more doesn't begin with q!
// quiz
// Here are the words accepted:
// quackery
// quasar
// quilt
// quotient
// quiz
