/* Given the following output:
Please choose one of the following:
1) copy files
2) move files
3) remove files
4) quit
Enter the number of your choice:
a. Write a function that displays a menu of four numbered choices and asks you
to choose one. (The output should look like the preceding.) b. Write a function
that has two int arguments: a lower limit and an upper limit. The function
should read an integer from input. If the integer is outside the limits, the
function should print a menu again (using the function from part “a” of this
question) to reprompt the user and then get a new value. When an integer in
the proper limits is entered, the function should return that value to the
calling function. Entering a noninteger should cause the function to return the
quit value of 4. c. Write a minimal program using the functions from parts “a”
and “b” of this question. By minimal, we mean it need not actually perform the
actions promised by the menu; it should just show the choices and get a valid
response. */
#include <stdio.h>
void display_menu(void);
int handle_input(int, int);

int main(void) { printf("%d", handle_input(3, 5)); }

void display_menu(void) {
	printf("Please choose one of the following:\n");
	printf("1) copy files\t\t2) move files\n");
	printf("3) remove files\t\t4) quit\n");
	printf("Enter the number of your choice: \n");
}

int handle_input(int lower, int upper) {
	int input;
	while (1) {
		display_menu();
		if (scanf("%d", &input) == 1) {
			if (input >= lower && input <= upper) {
				while (getchar() != '\n')
					;
				return input;
			}
			printf(
				"\nYour input is outside bound, please input an interger "
				"between %d and %d\n\n",
				lower, upper);
			while (getchar() != '\n')
				;
		} else {
			while (getchar() != '\n')
				;
			printf("Invalid Input, Exiting the program,\n");
			return 4;
		}
	}
}
