// Define an array of 12 structures of the sort in question 3 and initialize it
// for a non-leap year.

struct Month {
	char name[10];
	char abb[4];
	int days;
	int month;
};

struct Month months[12] = {
	{"January", "Jan", 31, 1},	 {"February", "Feb", 28, 2},
	{"March", "Mar", 31, 3},	 {"April", "Apr", 30, 4},
	{"May", "May", 31, 5},		 {"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},		 {"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9}, {"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11}, {"December", "Dec", 31, 12},
};