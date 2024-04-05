/*
The 1988 United States Federal Tax Schedule was the simplest in recent times. It
had four categories, and each category had two rates. Here is a summary (dollar
amounts are taxable income):

Category                Tax
Single                  15% of first $17,850 plus 28% of excess
Head of Household       15% of first $23,900 plus 28% of excess
Married, Joint          15% of first $29,750 plus 28% of excess
Married, Separate       15% of first $14,875 plus 28% of excess

For example, a single wage earner with a taxable income of $20,000 owes 0.15 ×
$17,850
+ 0.28 × ($20,000−$17,850). Write a program that lets the user specify the tax
category and the taxable income and that then calculates the tax. Use a loop so
that the user can enter several tax cases.
*/

#include <stdio.h>

#define RATE1 0.15 // 15% rate
#define RATE2 0.28 // 28% rate

#define SINGLE_LIMIT 17850
#define HOH_LIMIT 23900 // Head of Household
#define MARRIED_JOINT_LIMIT 29750
#define MARRIED_SEPARATE_LIMIT 14875

// Function to calculate tax
double calculateTax(int category, double income) {
	double limit, tax;

	switch (category) {
	case 1: // Single
		limit = SINGLE_LIMIT;
		break;
	case 2: // Head of Household
		limit = HOH_LIMIT;
		break;
	case 3: // Married, Joint
		limit = MARRIED_JOINT_LIMIT;
		break;
	case 4: // Married, Separate
		limit = MARRIED_SEPARATE_LIMIT;
		break;
	default:
		printf("Invalid category.\n");
		return 0.0;
	}

	if (income <= limit) {
		tax = RATE1 * income;
	} else {
		tax = RATE1 * limit + RATE2 * (income - limit);
	}

	return tax;
}

int main() {
	int category;
	double income, tax;

	while (1) {
		// Display menu
		printf("Tax Categories:\n");
		printf("1) Single\n");
		printf("2) Head of Household\n");
		printf("3) Married, Joint\n");
		printf("4) Married, Separate\n");
		printf("5) Quit\n");
		printf("Select your tax category (1-5): ");
		scanf("%d", &category);

		if (category == 5)
			break; // Exit condition

		printf("Enter taxable income: ");
		scanf("%lf", &income);

		tax = calculateTax(category, income);

		printf("Total tax: $%.2f\n\n", tax);
	}

	printf("Thank you for using the tax calculator.\n");

	return 0;
}

// Output:
/*
Tax Categories:
1) Single
2) Head of Household
3) Married, Joint
4) Married, Separate
5) Quit
Select your tax category (1-5): 1
Enter taxable income: 100000
Total tax: $25679.50

Tax Categories:
1) Single
2) Head of Household
3) Married, Joint
4) Married, Separate
5) Quit
Select your tax category (1-5): 2
Enter taxable income: 3000000000
Total tax: $839996893.00

Tax Categories:
1) Single
2) Head of Household
3) Married, Joint
4) Married, Separate
5) Quit
Select your tax category (1-5): 3
Enter taxable income: 40000
Total tax: $7332.50

Tax Categories:
1) Single
2) Head of Household
3) Married, Joint
4) Married, Separate
5) Quit
Select your tax category (1-5): 4
Enter taxable income: 1231412421
Total tax: $344793544.13

Tax Categories:
1) Single
2) Head of Household
3) Married, Joint
4) Married, Separate
5) Quit
Select your tax category (1-5): 5
Thank you for using the tax calculator.
*/
