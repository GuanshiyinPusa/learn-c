// Flexible array members
// One special property is that the array doesn’t
// exist—at least, not immediately. The second special property is that, with
// the right code, you can use the flexible array member as if it did exist and
// has whatever number of elements you need.

// here are the rules for declaring a flexible array member:
// ■The flexible array member must be the last member of the structure.
// ■There must be at least one other member.
// ■The flexible array is declared like an ordinary array, except that the
// brackets are empty.
// If you declare a variable of type struct flex, you can’t use scores for
// anything, because no memory space is set-aside for it. In fact, it’s not
// intended that you ever declare variables of the struct flex type. Instead,
// you are supposed to declare a pointer to the struct flex type and
// then use malloc() to allocate enough space for the ordinary contents of
// struct flex plus any extra space you want for the flexible array member. For
// example, suppose you want scores to represent an array of five double values.
// Then you would do this:
// struct flex *pf; // declare a pointer
// ask for space for a structure and an array
// pf = malloc(sizeof(struct flex) + 5 * sizeof(double));
// Now you have a chunk of memory large enough to store count, average, and an
// array of five double values. You can use the pointer pf to access these
// members:
// pf->count = 5;       // set count member
// pf->scores[2] = 18.5;  // access an element of the array member
// flexmemb.c -- flexible array member (C99 feature)

// First, don’t use structure assignment for copying:
// struct flex * pf1, *pf2;
// *pf1 and *pf2 are structures
// ...
// *pf2 = *pf1;
// don't do this
// Second, don’t use this sort of structure with functions that pass structures
// by value. The reason is the same; passing an argument by value is like
// assignment. Instead, use functions that pass the address of the structure.
// Third, don’t use a structure with a flexible array member as an element of an
// array or a member of another structure.
#include <stdio.h>
#include <stdlib.h>

struct flex {
	size_t count;
	double average;
	double scores[]; // flexible array member
};

void showFlex(const struct flex *p);

int main(void) {
	struct flex *pf1, *pf2;
	int n = 5;
	int i;
	float tot = 0;
	// allocate space for structure plus array
	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf1->count = n;
	for (i = 0; i < n; i++) {
		pf1->scores[i] = 20.0 - i;
		tot += pf1->scores[i];
	}
	pf1->average = tot / n;
	showFlex(pf1);
	n = 9;
	tot = 0;
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (i = 0; i < n; i++) {
		pf2->scores[i] = 20.0 - i / 2.0;
		tot += pf2->scores[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);
	return 0;
}

void showFlex(const struct flex *p) {
	int i;
	printf("Scores : ");
	for (i = 0; i < p->count; i++)
		printf("%g ", p->scores[i]);
	printf("\nAverage: %g\n", p->average);
}