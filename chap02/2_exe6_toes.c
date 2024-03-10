/* toes.c -- a program that works out toes double and square */
#include <stdio.h>

int main(void) {
	int toes;
	int toes_double;
	int toes_square;

	toes = 10;

	toes_double = 2 * toes;
	toes_square = toes * toes;

	printf("toes: %d\n", toes);
	printf("toes double: %d\n", toes_double);
	printf("toes square: %d\n", toes_square);

	return 0;
}

/*
 * Output:
 * toes: 10
 * toes double: 20
 * toes square: 100
 */
