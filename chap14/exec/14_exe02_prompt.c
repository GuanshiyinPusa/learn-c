// Write a program that prompts the user to enter the day, month, and year. The
// month can be a month number, a month name, or a month abbreviation. The
// program then should return the total number of days in the year up through
// the given day. (Do take leap years into account.)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s_gets(char *st, int n);

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

int total_day(void) {
	int day;
	char month_input[20];
	int year;
	int total = 0;
	struct Month current_month;
	puts("Enter day");
	scanf("%d", &day);
	puts("Enter month");
	s_gets(month_input, 20);
	puts("Enter year");
	scanf("%d", &year);
	for (int i = 0; i < 12; i++) {
		current_month = months[i];
		if (strcmp(month_input, current_month.name) == 0 ||
			strcmp(month_input, current_month.abb) == 0 ||
			atoi(month_input) == current_month.month) {
			total += day;
			break;
		}
		total += current_month.days;
		if (i == 1 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
			total += 1; // Add an extra day for leap year
		}
	}
	return total;
};

char *s_gets(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) // i.e., ret_val != NULL
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}