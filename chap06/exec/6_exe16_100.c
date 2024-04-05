/*
Daphne invests $100 at 10% simple interest. (That is, every year, the investment
earns an interest equal to 10% of the original investment.) Deirdre invests $100
at 5% interest compounded annually. (That is, interest is 5% of the current
balance, including previous addition of interest.) Write a program that finds
how many years it takes for the value of Deirdre’s investment to exceed the
value of Daphne’s investment. Also show the two values at that time.
*/
#include <stdio.h>

int main(void) {
	const double DAPHNE_INVESTMENT = 100.0;
	const double DEIRDRE_INVESTMENT = 100.0;
	const double DAPHNE_INTEREST = 0.10;
	const double DEIRDRE_INTEREST = 0.05;
	double daphne_balance = DAPHNE_INVESTMENT;
	double deirdre_balance = DEIRDRE_INVESTMENT;
	int years = 0;

	while (deirdre_balance <= daphne_balance) {
		daphne_balance += DAPHNE_INVESTMENT * DAPHNE_INTEREST;
		deirdre_balance += deirdre_balance * DEIRDRE_INTEREST;
		years++;
	}

	printf(
		"After %d years, Deirdre's investment exceeds Daphne's investment.\n",
		years);
	printf("Daphne's investment: $%.2f\n", daphne_balance);
	printf("Deirdre's investment: $%.2f\n", deirdre_balance);

	return 0;
}
