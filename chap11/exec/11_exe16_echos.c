// Write a program that reads input until end-of-file and echoes it to the
// display. Have the program recognize and implement the following command-line
// arguments: -p   Print input as is -u   Map input to all uppercase -l   Map
// input to all lowercase Also, if there are no command-line arguments, let the
// program behave as if the –p argument had been used.

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int c;
	int print = 1;
	int upper = 0;
	int lower = 0;

	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				switch (argv[i][1]) {
				case 'p':
					print = 1;
					break;
				case 'u':
					upper = 1;
					break;
				case 'l':
					lower = 1;
					break;
				default:
					fprintf(stderr, "Invalid argument: %s\n", argv[i]);
					return 1;
				}
			}
		}
	}

	while ((c = getchar()) != EOF) {
		if (upper) {
			putchar(toupper(c));
		} else if (lower) {
			putchar(tolower(c));
		} else {
			putchar(c);
		}
	}

	return 0;
}

// Output:
// $ gcc 11_exe16_echos.c -o 11_exe16_echos
// $ ./11_exe16_echos
// Hello, World!
// Hello, World!
// $ ./11_exe16_echos -u
// Hello, World!
// HELLO, WORLD!
