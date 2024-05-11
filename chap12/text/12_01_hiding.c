/* What if you declare a variable in an inner block that has the same name as
one in the outer block? Then the name defined inside the block is the variable
used inside the block. We say it hides the outer definition. However, when
execution exits the inner block, the outer variable comes back into scope.
Listing 12.1 illustrates these points and more. */
// hiding.c -- variables in blocks
#include <stdio.h>

int main(void) {
	int x = 30; // original x

	printf("x in outer block: %d at %p\n", x, &x);
	{
		int x = 77; // new x, hides first x
		printf("x in inner block: %d at %p\n", x, &x);
	}
	printf("x in outer block: %d at %p\n", x, &x);
	while (x++ < 33) // original x
	{
		int x = 100; // new x, hides first x
		x++;
		printf("x in while loop: %d at %p\n", x, &x);
	}
	printf("x in outer block: %d at %p\n", x, &x);
	return 0;
}

// Output:
// x in outer block: 30 at 0x7ffda4783900
// x in inner block: 77 at 0x7ffda4783904
// x in outer block: 30 at 0x7ffda4783900
// x in while loop: 101 at 0x7ffda4783904
// x in while loop: 101 at 0x7ffda4783904
// x in while loop: 101 at 0x7ffda4783904
// x in outer block: 34 at 0x7ffda4783900
