// talkback.c -- nosy, informative program
// It uses an array to hold a character string.
// %s conversion specification
#include <stdio.h>
#include <string.h>	 // for strlen() prototype
#define DENSITY 62.4 // human density in lbs per cu ft, using C processor.

int main(void) {
	float weight, volume;
	int size, letters;
	char name[40]; // name is an array of 40 chars

	printf("Hi! What's your first name?\n");
	scanf("%s", name); // note & is not used
	printf("%s, what's your weight in pounds?\n",
		   name); // notice name is a string
	scanf("%f", &weight);
	size = sizeof(name);
	letters = strlen(name); // find the length of a string
	volume = weight / DENSITY;
	printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
	printf("Also, your first name has %d letters,\n", letters);
	printf("and we have %d bytes to store it.\n", size);

	return 0;
}

/*
 * Output:
 * Hi! What's your first name?
 * John
 * John, what's your weight in pounds?
 * 180
 * Well, John, your volume is 2.89 cubic feet.
 * Also, your first name has 4 letters,
 * and we have 40 bytes to store it.
 */
