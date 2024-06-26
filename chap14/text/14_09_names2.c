/* names2.c -- passes and returns structures */
#include <stdio.h>
#include <string.h>
#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char *s_gets(char *st, int n);

int main(void) {
	struct namect person;
	person = getinfo();
	person = makeinfo(person);
	showinfo(person);
	return 0;
}

struct namect getinfo(void) {
	struct namect temp;
	printf("Please enter your first name.\n");
	s_gets(temp.fname, NLEN);
	printf("Please enter your last name.\n");
	s_gets(temp.lname, NLEN);
	return temp;
}

struct namect makeinfo(struct namect info) {
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}

void showinfo(struct namect info) {
	printf(
		"%s %s, your name contains %d letters.\n", info.fname, info.lname,
		info.letters);
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n'); // look for newline
		if (find)				 // if the address is not NULL,
			*find = '\0';		 // place a null character there
		else
			while (getchar() != '\n')
				continue; // dispose of rest of line
	}
	return ret_val;
}

// Output:
// Please enter your first name.
// Shuyuan
// Please enter your last name.
// Gao
// Shuyuan Gao, your name contains 10 letters.

// The two advantages of the pointer argument method are that it works on older
// as well as newer C implementations and that it is quick; you just pass a
// single address. The disadvantage is that you have less protection for your
// data. Some operations in the called function could inadver- tently affect
// data in the original structure. However, the ANSI C addition of the const
// qualifier solves that problem.