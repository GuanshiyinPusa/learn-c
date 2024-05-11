// Consider the following declarations:
struct fullname {
	char fname[20];
	char lname[20];
};

struct bard {
	struct fullname name;
	int born;
	int died;
};
struct bard willie;
struct bard *pt = &willie;
/*
a. Identify the born member of the willie structure using the willie identifier.
willie.born
b. Identify the born member of the willie structure using the pt identifier.
pt->born
c. Use a scanf() call to read in a value for the born member using the willie
identifier.
scanf("%d", &willie.born);
d. Use a scanf() call to read in a value for the born member using the pt
identifier.
scanf("%d", &pt->born);
e. Use a scanf() call to read in a value for the lname member of the
name member using the willie identifier.
scanf("%s", willie.name.lname);
f. Use a scanf() call to read in a value for the lname member of the name member
using the pt identifier.
scanf("%s", pt->name.lname);
g. Construct an identifier for the third letter of the first name of someone
described by the willie variable.
willie.name.fname[2]
h. Construct an expression representing the total number of letters in the first
and last names of someone described by the willie variable.
strlen(willie.name.fname) + strlen(willie.name.lname)
*/