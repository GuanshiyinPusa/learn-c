// Write a program with the following behavior.
// First, it asks you how many words you wish to enter.
// Then it has you enter the words, and then it displays the words.
// Use malloc() and the answer to the first question (the number of words) to
// create a dynamic array of the corresponding number of pointers-to-char. (Note
// that because each element in the array is a pointer-to-char, the pointer used
// to store the return value of malloc() should be a
// pointer-to-a-pointer-to-char.) When reading the string, the program should
// read the word into a temporary array of char, use malloc() to allocate enough
// storage to hold the word, and store the address in the array of char
// pointers. Then it should copy the word from the temporary array into the
// allocated storage. Thus, you wind up with an array of character pointers,
// each pointing to an object of the precise size needed to store the particular
// word. A sample run could look like this:
// How many words do you wish to enter? 5
// Enter 5 words now:
// I enjoyed doing this exerise
// Here are your words:
// I
// enjoyed
// doing
// this
// exercise
#include <stdio.h>
#include <stdlib.h>

#define WORDLENGTH 10

int main(void) {
	int num;
	printf("How many words do you wish to enter? ");
	scanf("%d", &num);
	printf("Enter %d words now:\n", num);
	char(*p)[WORDLENGTH];
	p = (char(*)[WORDLENGTH])malloc(num * WORDLENGTH * sizeof(char));
	for (int i = 0; i < num; i++) {
		scanf("%s", p[i]);
	}
	printf("Here are your words:\n");
	for (int i = 0; i < num; i++) {
		printf("%s\n", p[i]);
	}
}