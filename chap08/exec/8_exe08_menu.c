/*
Write a program that shows you a menu offering you the choice of addition,
subtraction, multiplication, or division. After getting your choice, the program
asks for two numbers, then performs the requested operation. The program should
accept only the offered menu choices. It should use type float for the numbers
and allow the user to try again if he or she fails to enter a number. In the
case of division, the program should prompt the user to enter a new value if 0
is entered as the value for the second number. A typical program run should look
like this: Enter the operation of your choice: a. add s. subtract m. multiply d.
divide q. quit
a
Enter first number: 22.4
Enter second number: one
one is not an number.
Please enter a number, such as 2.5, -1.78E8, or 3: 1
22.4 + 1 = 23.4
Enter the operation of your choice:
a. add
s. subtract
m. multiply
d. divide
q. quit
d
Enter first number: 18.4
Enter second number: 0
Enter a number other than 0: 0.2
18.4 / 0.2 = 92
Enter the operation of your choice:
a. add
s. subtract
m. multiply
d. divide
q. quit
q
Bye.
*/
// Import necessary libraries
#include <stdbool.h>
#include <stdio.h>

// Function Declarations
char get_choice();
float get_number();
float add(float a, float b);
float minus(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main(void) {
	char choice;

	do {
		printf("Enter the operation of your choice:\n");
		printf("a. add\t\ts. subtract\n");
		printf("m. multiply\td. divide\n");
		printf("q. quit\n");
		choice = get_choice();

		if (choice == 'q')
			break; // Exit if choice is 'q'

		printf("Enter first number: ");
		float a = get_number();
		printf("Enter second number: ");
		float b = get_number();

		// For division, ensure the second number is not zero
		while (choice == 'd' && b == 0) {
			printf("Enter a number other than 0: ");
			b = get_number();
		}

		switch (choice) {
		case 'a':
			printf("%.2f + %.2f = %.2f\n", a, b, add(a, b));
			break;
		case 's':
			printf("%.2f - %.2f = %.2f\n", a, b, minus(a, b));
			break;
		case 'm':
			printf("%.2f * %.2f = %.2f\n", a, b, multiply(a, b));
			break;
		case 'd':
			printf("%.2f / %.2f = %.2f\n", a, b, divide(a, b));
			break;
		}
	} while (choice != 'q');

	printf("Bye.\n");
	return 0;
}

float get_number() {
	float a;
	scanf("%f", &a);
	return a;
}

// Function to read the user's choice and validate it
char get_choice() {
	char ch;
	while (true) {
		ch = getchar();
		while (ch != '\n' && getchar() != '\n')
			; // Clear the buffer
		if (ch == 'a' || ch == 's' || ch == 'm' || ch == 'd' || ch == 'q') {
			return ch;
		} else {
			printf("Please enter a valid choice (a, s, m, d, q).\n");
		}
	}
}

// TODO: Implement each operation by prompting for two floats
float add(float a, float b) { return a + b; }

float minus(float a, float b) { return a - b; }

float multiply(float a, float b) { return a * b; }

float divide(float a, float b) {
	if (b == 0)
		printf("Denominator can't be 0\nGive me sth else: ");
	return a / b;
}
