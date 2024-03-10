/*
Write a program that requests your height in inches and your name, and then
displays the information in the following form: Dabney, you are 6.208 feet tall
Use type float, and use / for division. If you prefer, request the height in
centimeters and display it in meters.
*/

#include <stdio.h>
int main(void) {
	char first[40];
	float height;

	printf("Please enter your first name:\n");
	scanf("%s", first);
	printf("Please enter your height in inches:\n");
	scanf("%f", &height);
	printf("%s, you are %.3f feet tall\n", first, height / 12);

	return 0;
}

// Output:
// Please enter your first name:
// Shuyuan
// Please enter your height in inches:
// 74
// Shuyuan, you are 6.167 feet tall
