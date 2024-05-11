/* complit.c -- compound literals */
#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
	// structure template: tag is book
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void) {
	struct book readfirst;
	int score;
	printf("Enter test score: ");
	scanf("%d", &score);
	if (score >= 84)
		readfirst =
			(struct book){"Crime and Punishment", "Fyodor Dostoyevsky", 11.25};
	else
		readfirst =
			(struct book){"Mr. Bouncy's Nice Hat", "Fred Winsome", 5.99};
	printf("Your assigned reading:\n");
	printf(
		"%s by %s: $%.2f\n", readfirst.title, readfirst.author,
		readfirst.value);
	return 0;
}

// Output:
// Your assigned reading:
// Crime and Punishment by Fyodor Dostoyevsky: $11.25
// [gsy@guanshiyinpusa text]$ ./a.out
// Enter test score: 12
// Your assigned reading:
// Mr. Bouncy's Nice Hat by Fred Winsome: $5.99

// You also can use compound literals as arguments to functions. If the function
// expects a struc- ture, you can pass the compound literal as the actual
// argument: struct rect {double x; double y;}; double rect_area(struct rect
// r){return r.x * r.y;}
// double area;
// area = rect_area( (struct rect) {10.5, 20.0});

// If a function expects an address, you can pass the address of a compound
// literal: struct rect {double x; double y;}; double rect_areap(struct rect *
// rp){return rp->x * rp->y;}
// ...
// double area;
// area = rect_areap( &(struct rect) {10.5, 20.0});