/* funds1.c -- passing structure members as arguments */
#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

// if you want a called function to affect the value of a member in the calling
// function, you can transmit the address of the member:
// modify(&stan.bankfund);
double sum(double, double);

int main(void) {
	struct funds stan = {
		"Garlic-Melon Bank", 4032.27, "Lucky's Savings and Loan", 8543.94};
	printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));
	return 0;
}

/* adds two double numbers */
double sum(double x, double y) { return (x + y); }

// Output:
// Stan has a total of $12576.21.