// Write a program that creates a structure template with two members according
// to the following criteria: a. The first member is a social security number.
// The second member is a structure with three members. Its first member
// contains a first name, its second member contains a middle name, and its
// final member contains a last name. Create and initialize an array of five
// such structures. Have the program print the data in this format:
#include <stdio.h>

struct personal_info {
	long int social_security_number;

	struct name {
		char first_name[10];
		char middle_name[10];
		char last_name[10];
	} instance;
};

// Dribble, Flossie M. –– 302039823
// Only the initial letter of the middle name is printed, and a period is added.
// Neither the initial (of course) nor the period should be printed if the
// middle name member is empty. Write a function to do the printing; pass the
// structure array to the function.
// b. Modify part a. by passing the structure value instead of the address.

void print_info(struct personal_info input[], int size);

void print_info2(struct personal_info input);

int main(void) {
	struct personal_info people[5] = {
		[1] = {302039823, {"Dribble", "Mtf", "Flossie"}}};
	print_info(people, 5);
	print_info2(people[1]);
}

void print_info(struct personal_info input[], int size) {
	if (input[1].instance.middle_name[0] != '\0') {
		printf(
			"%s, %s %c. -- %ld\n", input[1].instance.first_name,
			input[1].instance.last_name, input[1].instance.middle_name[0],
			input[1].social_security_number);
	} else {
		printf(
			"%s, %s -- %ld\n", input[1].instance.first_name,
			input[1].instance.last_name, input[1].social_security_number);
	}
}

void print_info2(struct personal_info input) {
	if (input.instance.middle_name[0] != '\0') {
		printf(
			"%s, %s %c. -- %ld\n", input.instance.first_name,
			input.instance.last_name, input.instance.middle_name[0],
			input.social_security_number);
	} else {
		printf(
			"%s, %s -- %ld\n", input.instance.first_name,
			input.instance.last_name, input.social_security_number);
	}
}