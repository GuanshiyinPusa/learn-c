// Suppose you have the following declaration:
// int grid[30][100];

// a. Express the address of grid[22][56] one way.
// &grid[22][56]
// b. Express the address of grid[22][0] two ways.
// &grid[22][0] or grid[22]
// c. Express the address of grid[0][0] three ways.
// &grid[0][0] or grid[0] or (int *)grid

#include <stdio.h>

int main(void) {
	int grid[30][100];

	printf("%p\n", &grid[22][56]);
	printf("%p\t%p\n", &grid[22][0], grid[22]);
	printf("%p\t%p\t%p\n", &grid[0][0], grid[0], (int *)grid);
}

// Output:
// 0x7fff1ba88a10
// 0x7fff1ba88930  0x7fff1ba88930
// 0x7fff1ba866d0  0x7fff1ba866d0  0x7fff1ba866d0
