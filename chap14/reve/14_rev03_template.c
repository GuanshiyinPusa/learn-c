// Devise a structure template that will hold the name of a month, a
// three-letter abbreviation for the month, the number of days in the month, and
// the month number.

struct month {
	char name[10];
	char abb[4];
	int days;
	int month;
};