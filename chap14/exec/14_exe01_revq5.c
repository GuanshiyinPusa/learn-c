// Redo Review Question 5, but make the argument the spelled-out name of the
// month instead of the month number. (Don’t forget about strcmp().) Test the
// function in a simple program.
#include <stdio.h>
#include <string.h>

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
	char month_name[] = "December";
	int total_days = 0;
	for (int i = 0; i < 12; i++) {
		total_days += months[i].days;
		if (!strcmp(months[i].name, month_name))
			break;
	}
	printf("%d", total_days);
	return 0;
}
