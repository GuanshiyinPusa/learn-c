/*
Write a program that requests the hours worked in a week and then prints the
gross pay, the taxes, and the net pay. Assume the following: a. Basic pay rate =
$10.00/hr b. Overtime (in excess of 40 hours) = time and a half c. Tax rate:
#15% of the first $300 20% of the next $150 25% of the rest Use #define
constants, and don’t worry if the example does not conform to current tax law.
*/

#include <stdio.h>
#define BASIC_PAY_RATE 10.00
#define OVERTIME_HOURS 40
#define OVERTIME_RATE 1.5
#define TAX_RATE_1 0.15 // 15% for the first $300
#define TAX_RATE_2 0.20 // 20% for the next $150
#define TAX_RATE_3 0.25 // 25% for the rest
#define TAX_BRACKET_1 300
#define TAX_BRACKET_2 450 // $300 + $150

int main() {
	double hoursWorked, grossPay, taxes, netPay;
	double overtimePay = 0.0;

	// Request input
	printf("Enter the number of hours worked in a week: ");
	scanf("%lf", &hoursWorked);

	// Calculate gross pay
	if (hoursWorked > OVERTIME_HOURS) {
		overtimePay =
			(hoursWorked - OVERTIME_HOURS) * BASIC_PAY_RATE * OVERTIME_RATE;
		grossPay = OVERTIME_HOURS * BASIC_PAY_RATE + overtimePay;
	} else {
		grossPay = hoursWorked * BASIC_PAY_RATE;
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
	printf("Net Pay: $%.2f\n", netPay);

	return 0;
}

// Output:
// Enter the number of hours worked in a week: 48
// Gross Pay: $520.00
// Taxes: $92.50
// Net Pay: $427.50
