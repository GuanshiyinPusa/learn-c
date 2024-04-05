/*
The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for $1.15
per pound, and carrots for $1.09 per pound. It gives a 5% discount for orders of
$100 or more prior to adding shipping costs. It charges $6.50 shipping and
handling for any order of 5 pounds or under, $14.00 shipping and handling for
orders over 5 pounds and under 20 pounds, and $14.00 plus $0.50 per pound for
shipments of 20 pounds or more. Write a program that uses a switch statement in
a loop such that a response of a lets the user enter the pounds of artichokes
desired, b the pounds of beets, c the pounds of carrots, and q allows the user
to exit the ordering process. The program should keep track of cumulative
totals. That is, if the user enters 4 pounds of beets and later enters 5 pounds
of beets, the program should use report 9 pounds of beets. The program then
should compute the total charges, the discount, if any, the shipping charges,
and the grand total. The program then should display all the purchase
information: the cost per pound, the pounds ordered, and the cost for that order
for each vegetable, the total cost of the order, the discount (if there is one),
the shipping charge, and the grand total of all the charges.
*/

#include <stdio.h>

#define PRICE_PER_POUND_ARTICHOKE 2.05
#define PRICE_PER_POUND_BEET 1.15
#define PRICE_PER_POUND_CARROT 1.09
#define DISCOUNT_THRESHOLD 100.00 // $100 for 5% discount
#define DISCOUNT_RATE 0.05		  // 5%
#define SHIPPING_5LBS 6.50
#define SHIPPING_5_20LBS 14.00
#define SHIPPING_20LBS_BASE 14.00
#define SHIPPING_OVER_20LBS_PER_POUND 0.50

int main() {
	char choice;
	double poundsArtichokes = 0, poundsBeets = 0, poundsCarrots = 0;
	double totalCost = 0, totalWeight = 0, discount = 0, shipping = 0,
		   grandTotal = 0;

	printf("ABC Mail Order Grocery\n");
	do {
		printf("\nMenu:\n");
		printf("a) Artichokes\n");
		printf("b) Beets\n");
		printf("c) Carrots\n");
		printf("q) Quit and proceed to checkout\n");
		printf("Enter your choice: ");
		scanf(" %c", &choice); // Note the space before %c to consume any
							   // newline characters

		double pounds = 0;
		switch (choice) {
		case 'a':
			printf("Enter pounds of artichokes: ");
			scanf("%lf", &pounds);
			poundsArtichokes += pounds;
			break;
		case 'b':
			printf("Enter pounds of beets: ");
			scanf("%lf", &pounds);
			poundsBeets += pounds;
			break;
		case 'c':
			printf("Enter pounds of carrots: ");
			scanf("%lf", &pounds);
			poundsCarrots += pounds;
			break;
		case 'q':
			printf("Proceeding to checkout...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 'q');

	// Calculate costs
	double costArtichokes = poundsArtichokes * PRICE_PER_POUND_ARTICHOKE;
	double costBeets = poundsBeets * PRICE_PER_POUND_BEET;
	double costCarrots = poundsCarrots * PRICE_PER_POUND_CARROT;
	totalCost = costArtichokes + costBeets + costCarrots;

	// Calculate discount
	if (totalCost > DISCOUNT_THRESHOLD) {
		discount = totalCost * DISCOUNT_RATE;
	}

	// Calculate total weight and shipping
	totalWeight = poundsArtichokes + poundsBeets + poundsCarrots;
	if (totalWeight <= 5) {
		shipping = SHIPPING_5LBS;
	} else if (totalWeight <= 20) {
		shipping = SHIPPING_5_20LBS;
	} else {
		shipping = SHIPPING_20LBS_BASE +
				   (totalWeight - 20) * SHIPPING_OVER_20LBS_PER_POUND;
	}

	// Calculate grand total
	grandTotal = totalCost - discount + shipping;

	// Display purchase information
	printf("\nPurchase Summary:\n");
	printf("Artichokes: %.2lf lbs at $%.2lf/lb = $%.2lf\n", poundsArtichokes,
		   PRICE_PER_POUND_ARTICHOKE, costArtichokes);
	printf("Beets: %.2lf lbs at $%.2lf/lb = $%.2lf\n", poundsBeets,
		   PRICE_PER_POUND_BEET, costBeets);
	printf("Carrots: %.2lf lbs at $%.2lf/lb = $%.2lf\n", poundsCarrots,
		   PRICE_PER_POUND_CARROT, costCarrots);
	printf("Total cost of vegetables: $%.2lf\n", totalCost);
	printf("Discount: -$%.2lf\n", discount);
	printf("Shipping: $%.2lf\n", shipping);
	printf("Grand total: $%.2lf\n", grandTotal);

	return 0;
}

// Output:
/*
ABC Mail Order Grocery

Menu:
a) Artichokes
b) Beets
c) Carrots
q) Quit and proceed to checkout
Enter your choice: a
Enter pounds of artichokes: 2

Menu:
a) Artichokes
b) Beets
c) Carrots
q) Quit and proceed to checkout
Enter your choice: b
Enter pounds of beets: 1

Menu:
a) Artichokes
b) Beets
c) Carrots
q) Quit and proceed to checkout
Enter your choice: c
Enter pounds of carrots: 1

Menu:
a) Artichokes
b) Beets
c) Carrots
q) Quit and proceed to checkout
Enter your choice: q
Proceeding to checkout...

Purchase Summary:
Artichokes: 2.00 lbs at $2.05/lb = $4.10
Beets: 1.00 lbs at $1.15/lb = $1.15
Carrots: 1.00 lbs at $1.09/lb = $1.09
Total cost of vegetables: $6.34
Discount: -$0.00
Shipping: $6.50
Grand total: $12.84
*/
