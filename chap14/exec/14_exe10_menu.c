// Write a program that implements a menu by using an array of pointers to
// functions. For instance, choosing a from the menu would activate the function
// pointed to by the first element of the array.
#include <stdio.h>

// Function prototypes
void functionA();
void functionB();
void functionC();

// Array of function pointers
void (*functionArray[3])() = {functionA, functionB, functionC};

int main() {
	char choice;

	printf("Enter a choice (a, b, c): ");
	scanf(" %c", &choice);

	switch (choice) {
	case 'a':
		(*functionArray[0])();
		break;
	case 'b':
		(*functionArray[1])();
		break;
	case 'c':
		(*functionArray[2])();
		break;
	default:
		printf("Invalid choice\n");
	}

	return 0;
}

void functionA() { printf("You chose 'a'\n"); }

void functionB() { printf("You chose 'b'\n"); }

void functionC() { printf("You chose 'c'\n"); }