/*
Modify assumption a. in exercise 7 so that the program presents a menu of pay
rates from which to choose. Use a switch to select the pay rate. The beginning
of a run should look something like this:
*****************************************************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr
2) $9.33/hr
3) $10.00/hr
4) $11.20/hr
5) quit
*****************************************************************
If choices 1 through 4 are selected, the program should request the hours
worked. The program should recycle until 5 is entered. If something other than
choices 1 through 5 is entered, the program should remind the user what the
proper choices are and then recycle. Use #defined constants for the various
earning rates and tax rates.
*/

#include <stdio.h>
#define OVERTIME_HOURS 40
#define OVERTIME_RATE 1.5
#define TAX_RATE_1 0.15 // 15% for the first $300
#define TAX_RATE_2 0.20 // 20% for the next $150
#define TAX_RATE_3 0.25 // 25% for the rest
#define TAX_BRACKET_1 300
#define TAX_BRACKET_2 450 // $300 + $150

int main() {
	int choice;
	double payRate, hoursWorked, grossPay, taxes, netPay;

	do {
		// Display menu
		printf("***************************************************************"
			   "**\n");
		printf("Enter the number corresponding to the desired pay rate or "
			   "action:\n");
		printf("1) $8.75/hr\n");
		printf("2) $9.33/hr\n");
		printf("3) $10.00/hr\n");
		printf("4) $11.20/hr\n");
		printf("5) quit\n");
		printf("***************************************************************"
			   "**\n");

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			payRate = 8.75;
			break;
		case 2:
			payRate = 9.33;
			break;
		case 3:
			payRate = 10.00;
			break;
		case 4:
			payRate = 11.20;
			break;
		case 5:
			printf("Quitting program.\n");
			return 0;
		default:
			printf("Please enter a valid choice (1-5).\n");
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

	} while (choice != 5);

	return 0;
}

// Output:
/* *****************************************************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr
2) $9.33/hr
3) $10.00/hr
4) $11.20/hr
5) quit
*****************************************************************
1
Enter the number of hours worked in a week: 40
Gross Pay: $350.00
Taxes: $55.00
Net Pay: $295.00

*****************************************************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr
2) $9.33/hr
3) $10.00/hr
4) $11.20/hr
5) quit
*****************************************************************
4
Enter the number of hours worked in a week: 50
Gross Pay: $616.00
Taxes: $116.50
Net Pay: $499.50 */
