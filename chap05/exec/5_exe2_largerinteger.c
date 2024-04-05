/*
Write a program that asks for an integer and then prints all the integers from
(and including) that value up to (and including) a value larger by 10. (That is,
if the input is 5, the output runs from 5 to 15.) Be sure to separate each
output value by a space or tab or newline.
*/
#include <stdio.h>

int main(void) {
	int num;
	printf("Enter an integer: ");
	scanf("%d", &num);
	int limit = num + 10;
	while (num <= limit) {
		printf("%d ", num);
		num++;
	}
	printf("\n");
	return 0;
}

// Output:
// Enter an integer: 100
// 100 101 102 103 104 105 106 107 108 109 110
