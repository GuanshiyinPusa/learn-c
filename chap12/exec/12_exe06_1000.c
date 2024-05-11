// Write a program that generates 1,000 random numbers in the range 1–10. Don’t
// save or print the numbers, but do print how many times each number was
// produced. Have the program do this for 10 different seed values. Do the
// numbers appear in equal amounts? You can use the functions from this chapter
// or the ANSI C rand() and srand() functions, which follow the same format that
// our functions do. This is one way to examine the randomness of a particular
// random-number generator.
#include <stdio.h>
#include <stdlib.h>

#define NUM_SEEDS 10
#define NUM_NUMBERS 1000

int main() {
	for (int seed = 1; seed <= NUM_SEEDS; seed++) {
		srand(seed);
		int counts[10] = {0};

		for (int i = 0; i < NUM_NUMBERS; i++) {
			int random_num = rand() % 10 + 1;
			counts[random_num - 1]++;
		}

		printf("Seed value: %d\n", seed);
		for (int i = 0; i < 10; i++) {
			printf("%d occurred %d times\n", i + 1, counts[i]);
		}
		printf("\n");
	}

	return 0;
}
