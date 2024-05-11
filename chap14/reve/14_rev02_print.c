// Here is a portion of a program. What will it print?
#include <stdio.h>

struct house {
	float sqft;
	int rooms;
	int stories;
	char address[40];
};

int main(void) {
	// initialize a struct -- fruzt
	struct house fruzt = {1560.0, 6, 1, "22 Spiffo Road"};
	// initialize a struct pointer -- sign
	struct house *sign;
	// sign points to the address of fruzt
	sign = &fruzt;
	// print fruzt.rooms --> 6, sign->stories --> 1
	printf("%d %d\n", fruzt.rooms, sign->stories);
	// print fruzt.address --> 22 Spiffo Road
	printf("%s \n", fruzt.address);
	// print sign->address[3] --> "S", fruzt.address[4] --> "p"
	printf("%c %c\n", sign->address[3], fruzt.address[4]);
	return 0;
}

// print
// 6 1
// 22 Spiffo Road
// S p