// Which functions know each variable in the following ? Are there any errors?
/* file 1 */
int daisy; // accessiable to file 2, using extern to access it.

int main(void) {
	int lily; // automatic variable, only accessiable to main function.
			  // ...;
}

int petal() {
	extern int daisy, lily; // daisy is accessiable, lily is not.
							// ...;
}

/* file 2 */
extern int daisy;
static int lily; // only accessible to current file
int rose;		 // global rose

int stem() {
	int rose; // local rose
			  // ...;
}

void root() {
	// ...;
}
