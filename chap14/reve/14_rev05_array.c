/* Write a function that, when given the month number, returns the total days in
the year up to and including that month. Assume that the structure template of
question 3 and an appropriate array of such structures are declared externally
*/
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

int main(void) {
	int month_num = 10;
	int total_days = 0;
	for (int i = 0; i < month_num; i++) {
		total_days += months[i].days;
	}
	return 0;
}