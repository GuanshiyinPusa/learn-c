/*
Chuckie Lucky won a million dollars (after taxes), which he places in an account
that earns 8% a year. On the last day of each year, Chuckie withdraws $100,000.
Write a program that finds out how many years it takes for Chuckie to empty his
account.
*/

#include <stdio.h>

int main(void) {
	const double INVESTMENT = 1000000.0;
	const double INTEREST = 0.08;
	double balance = INVESTMENT;
	int years = 0;

	while (balance > 0) {
		balance += balance * INTEREST;
		balance -= 100000;
		years++;
	}

	printf("After %d years, Chuckie will empty his account.\n", years);

	return 0;
}
