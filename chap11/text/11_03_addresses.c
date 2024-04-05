// addresses.c -- addresses of strings
#define MSG "I'm special."

#include <stdio.h>

int main(void) {
	char ar[] = MSG;
	const char *pt = MSG;
	printf("address of \"I'm special\": %p \n", "I'm special");
	printf("\t\t\taddress ar: %p\n", ar);
	printf("\t\taddress pt: %p\n", pt);
	printf("\taddress of MSG: %p\n", MSG);
	printf("address of \"I'm special\": %p \n", "I'm special");
}

// NOTE: Diff between * pt1 and ar1[]
// For ar1[]
// ar1 is recognized as the address constant of the first element,
// You can't change ar1, so no ++ar1, but ar1 + 1 for next element
// But you can change the string, since it's not constant.
// For *pt1
// the value can be changed, so ++pt1 can points to next element.
// The string literal is a const data, which pt1 points to.
// You can't change the string literal.

// INFO: IN SHORT: initializing the array copies a string from static storage to
// the array, whereas initializing the pointer merely copies the address of the
// string.

// char heart[] = "I love Tillie!";
// const char *head = "I love Millie!";
// The chief difference is that the array name heart is a constant, but the
// pointer head is a vari- able. both can use array notation and array addition.
// Only the pointer version, however, can use the increment operator:
// while (*(head) != '\0') /* stop at end of string*/
// 	putchar(*(head++)); /* print character, advance pointer */

// Suppose you want head to agree with heart. You can say
// head = heart;
// /* head now points to the array heart */
// This makes the head pointer point to the first element of the heart array.
// However, you cannot say
// heart = head;    /* illegal construction */
// There is a way to alter the heart message—go to the individual array
// elements: heart[7]= 'M'; or
// *(heart + 7) = 'M';
// The elements of an array are variables (unless the array was declared as
// const), but the name is not a variable.

// the recommended practice for initializing a pointer to a string literal is to
// use the const modifier:
// const char * pl = "Klingon";// recommended usage
// Initializing a non-const array with a string literal, however, poses no such
// problems, because the array gets a copy of the original string. In short,
// don’t use a pointer to a string literal if you plan to alter the string.
