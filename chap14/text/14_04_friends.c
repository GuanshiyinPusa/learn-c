/* friends.c -- uses pointer to a structure */
#include <stdio.h>
#define LEN 20

struct names {
	char first[LEN];
	char last[LEN];
};

struct guy {
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

// First Way
// him->income is barney.income if him == &barney
// him->income is fellow[0].income if him == &fellow[0]
// him->income is therefore float type
// Second way
// fellow[0].income == (*him).income
// The parentheses are required because the . operator has higher precedence
// than *.
// barney.income == (*him).income == him->income
// assuming him == &barney

int main(void) {
	struct guy fellow[2] = {
		{{"Ewen", "Villard"}, "grilled salmon", "personality coach", 68112.00},
		{{"Rodney", "Swillbelly"}, "tripe", "tabloid editor", 232400.00}};
	struct guy *him; /* here is a pointer to a structure */
	printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
	him = &fellow[0]; /* tell the pointer where to point */
	printf("pointer #1: %p #2: %p\n", him, him + 1);
	printf(
		"him->income is $%.2f: (*him).income is $%.2f\n", him->income,
		(*him).income);
	him++; /* point to the next structure */
	printf(
		"him->favfood is %s: him->handle.last is %s\n", him->favfood,
		him->handle.last);
	return 0;
}

// Output:
// address #1: 0x7fff2307d1f0 #2: 0x7fff2307d244
// pointer #1: 0x7fff2307d1f0 #2: 0x7fff2307d244
// him->income is $68112.00: (*him).income is $68112.00
// him->favfood is tripe: him->handle.last is Swillbelly