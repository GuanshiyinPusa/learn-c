/* What will this program print? */
#include <stdio.h>

int main(void) {
	char note[] = "See you at the snack bar."; // initialize a string
	char *ptr;								   // initilaze a pointer
	ptr = note;		// point the pointer to the string
	puts(ptr);		// See you at the snack bar.
	puts(++ptr);	// print the string after incrementing the pointer
	note[7] = '\0'; // set the 8th character to null
	puts(note);		// See you
	puts(++ptr);	// ee you
	return 0;
}
