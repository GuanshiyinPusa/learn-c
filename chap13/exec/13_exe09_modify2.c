// Modify the program in Listing 13.3 so that each word is numbered according to
// the order in which it was added to the list, starting with 1. Make sure that,
// when the program is run a second time, new word numbering resumes where the
// previous numbering left off.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void) {
	FILE *fp;
	char words[MAX];
	int count = 0;
	int temp;

	if ((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	// Find the last count
	rewind(fp);
	while (fscanf(fp, "%d %40s", &temp, words) == 2)
		count = temp;

	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	// fscanf stop when it meets whitespace.
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%d %s\n", ++count, words);
	puts("File contents:");
	rewind(fp); /* go back to beginning of file */
	while (fscanf(fp, "%d %s", &temp, words) == 2)
		printf("%d %s\n", temp, words);
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	return 0;
}