// Work out number of water molecules in quart.
#include <stdio.h>

int main(void) {
	double water_molecule_gram = 3.0e23;
	double waterquart = 950.0;

	double numinquart = waterquart / water_molecule_gram;

	printf("There are %f water molecules in one quart of water", numinquart);

	return 0;
}

/*
 * Output:
 * There are 3.166667 water molecules in one quart of water
 */
