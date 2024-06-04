/* qsorter.c -- using qsort to sort groups of numbers */
#include <stdio.h>
#include <stdlib.h>

#define NUM 40
void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void *p1, const void *p2);

int main(void) {
	double vals[NUM];
	fillarray(vals, NUM);
	puts("Random list:");
	showarray(vals, NUM);
	qsort(vals, NUM, sizeof(double), mycomp);
	puts("\nSorted list:");
	showarray(vals, NUM);
	return 0;
}

void fillarray(double ar[], int n) {
	int index;

	for (index = 0; index < n; index++)
		ar[index] = (double)rand() / ((double)rand() + 0.1);
}

void showarray(const double ar[], int n) {
	int index;

	for (index = 0; index < n; index++) {
		printf("%9.4f ", ar[index]);
		if (index % 6 == 5)
			putchar('\n');
	}
	if (index % 6 != 0)
		putchar('\n');
}

/* sort by increasing value */
int mycomp(const void *p1, const void *p2) {
	/* need to use pointers to double to access values  */
	const double *a1 = (const double *)
		p1; // Type cast before p1 is optional in C, mandatory in C++
	const double *a2 = (const double *)p2;

	if (*a1 < *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}

// struct names {
// 	char first[40];
// 	char last[40];
// };
// struct names staff[100];
// qsort(staff, 100, sizeof(struct names), comp);
// #include <string.h>

// int comp(const void *p1, const void *p2)
// /* mandatory form */
// {
// 	/* get right type of pointer */
// 	const struct names *ps1 = (const struct names *)p1;
// 	const struct names *ps2 = (const struct names *)p2;
// 	int res;
// 	res = strcmp(ps1->last, ps2->last); /* compare last names */
// 	if (res != 0)
// 		return res;
// 	else
// 		/* last names identical, so compare first names */
// 		return strcmp(ps1->first, ps2->first);
// }