// Write a file copy program that prompts the user to enter the name of a text
// file to act as the source file and the name of an output file. The program
// should use the toupper() function from ctype.h to convert all text to
// uppercase as it’s written to the output file. Use standard I/O and the text
// mode.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
char *s_gets(char *st, int n);

int main(int argc, char *argv[]) {
	char source[20];
	char output[20];
	char buffer[1024];
	size_t bytes_read;
	FILE *srce, *dest;
	printf("Enter the source file name: ");
	s_gets(source, 20);
	printf("Enter the output file name: ");
	s_gets(output, 20);
	if ((srce = fopen(source, "r")) && (dest = fopen(output, "w"))) {
		while ((bytes_read = fread(buffer, 1, sizeof(buffer), srce)) > 0) {
			// toupper()
			for (size_t i = 0; i < 1024; i++)
				buffer[i] = toupper(buffer[i]);
			if (fwrite(buffer, 1, bytes_read, dest) != bytes_read) {
				printf("Error writing to file: %s\n", argv[2]);
				fclose(srce);
				fclose(dest);
				exit(EXIT_FAILURE);
			}
		}
	}
	return 0;
}

char *s_gets(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) // i.e., ret_val != NULL
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
