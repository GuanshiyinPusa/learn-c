/* input.c -- when to use & */
#include <stdio.h>
int main(void) {
	int age;	   // variable
	float assests; // variable
	char pet[30];  // array

	printf("Enter your age, assests, and favorite pet.\n");
	scanf("%d %f", &age, &assests); // use the & here
	scanf("%s", pet);				// no & for char array
	printf("%d $%.2f %s\n", age, assests, pet);

	return 0;
}

// Output:
// Enter your age, assests, and favorite pet.
// 25 1234.56
// 25 $1234.56 1234.56
