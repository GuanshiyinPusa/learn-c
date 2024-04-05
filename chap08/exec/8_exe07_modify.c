#include <stdio.h>
#define OVERTIME_HOURS 40
#define OVERTIME_RATE 1.5
#define TAX_RATE_1 0.15 // 15% for the first $300
#define TAX_RATE_2 0.20 // 20% for the next $150
#define TAX_RATE_3 0.25 // 25% for the rest
#define TAX_BRACKET_1 300
#define TAX_BRACKET_2 450 // $300 + $150

int main() {
	char choice;
	double payRate, hoursWorked, grossPay, taxes, netPay;

	do {
		// Display menu with characters instead of numbers
		printf("***************************************************************"
			   "*\n");
		printf("Enter the letter corresponding to the desired pay rate or "
			   "action:\n");
		printf(
			"a) $8.75/hr\tb) $9.33/hr\nc) $10.00/hr\td) $11.20/hr\tq) quit\n");
		printf("***************************************************************"
			   "*\n");

		scanf(" %c", &choice); // Note the space before %c to consume any
							   // newline character left in the input buffer

		switch (choice) {
		case 'a':
			payRate = 8.75;
			break;
		case 'b':
			payRate = 9.33;
			break;
		case 'c':
			payRate = 10.00;
			break;
		case 'd':
			payRate = 11.20;
			break;
		case 'q':
			printf("Quitting program.\n");
			return 0;
		default:
			printf("Please enter a valid choice (a, b, c, d, q).\n");
			continue;
		}

		printf("Enter the number of hours worked in a week: ");
		scanf("%lf", &hoursWorked);

		// Calculate gross pay
		if (hoursWorked > OVERTIME_HOURS) {
			grossPay =
				(hoursWorked - OVERTIME_HOURS) * payRate * OVERTIME_RATE +
				OVERTIME_HOURS * payRate;
		} else {
			grossPay = hoursWorked * payRate;
		}

		// Calculate taxes
		if (grossPay <= TAX_BRACKET_1) {
			taxes = grossPay * TAX_RATE_1;
		} else if (grossPay <= TAX_BRACKET_2) {
			taxes = TAX_BRACKET_1 * TAX_RATE_1 +
					(grossPay - TAX_BRACKET_1) * TAX_RATE_2;
		} else {
			taxes = TAX_BRACKET_1 * TAX_RATE_1 +
					(TAX_BRACKET_2 - TAX_BRACKET_1) * TAX_RATE_2 +
					(grossPay - TAX_BRACKET_2) * TAX_RATE_3;
		}

		// Calculate net pay
		netPay = grossPay - taxes;

		// Print results
		printf("Gross Pay: $%.2f\n", grossPay);
		printf("Taxes: $%.2f\n", taxes);
		printf("Net Pay: $%.2f\n\n", netPay);

	} while (choice != 'q');

	return 0;
}
