// Write a program that fits the following recipe:
//
// a. Externally define a name structure template with two members: a string to
// hold the first name and a string to hold the second name.
#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);

struct name {
	char first_name[20];
	char second_name[20];
};

// b. Externally define a student structure template with three members: a name
// structure, a grade array to hold three floating-point scores, and a variable
// to hold the average of those three scores.
struct student {
	struct name student_name;
	double grade[3];
	double average_grade;
};

// c. Have the main() function declare an array of CSIZE (with CSIZE = 4)
// student structures and initialize the name portions to names of your choice.
// Use functions to perform the tasks described in parts d., e., f., and g.
#define CSIZE 4

int main(void) {
	struct student students[4] = {
		[0] =
			{
				{"Ma", "gar"},
				{50, 75, 100},
				75,
			},
		[1] =
			{
				{"ST", "G"},
				{100, 100, 100},
				100,
			},

	};
	// d. Interactively acquire scores for each student by prompting the user
	// with a student name and a request for scores. Place the scores in the
	// grade array portion of the appropriate structure. The required looping
	// can be done in main() or in the function, as you prefer.
	char input_first_name[20];
	char input_second_name[20];
	printf("First Name?\n");
	s_gets(input_first_name, 20);
	printf("Second Name?\n");
	s_gets(input_second_name, 20);
	int input_index = 0;
	// check for an empty slot
	while (input_index < CSIZE &&
		   students[input_index].student_name.first_name[0] != '\0') {
		input_index++;
	}

	// e. Calculate the average score value for each structure and assign it to
	// the proper member.

	strcpy(students[input_index].student_name.first_name, input_first_name);
	strcpy(students[input_index].student_name.second_name, input_second_name);
	scanf(
		"%lf %lf %lf", &students[input_index].grade[0],
		&students[input_index].grade[1], &students[input_index].grade[2]);
	students[input_index].average_grade =
		(students[input_index].grade[0] + students[input_index].grade[1] +
		 students[input_index].grade[2]) /
		3;
	// f. Print the information in each structure.
	for (int i = 0; i < CSIZE; i++) {
		printf(
			"Student: %s %s\n", students[i].student_name.first_name,
			students[i].student_name.second_name);
		printf(
			"Grades: %.2lf %.2lf %.2lf\n", students[i].grade[0],
			students[i].grade[1], students[i].grade[2]);
		printf("Average grade: %.2lf\n\n", students[i].average_grade);
	}

	// g. Print the class average for each of the numeric structure members.
	double total_average = 0;
	for (int i = 0; i < CSIZE; i++) {
		total_average += students[i].average_grade;
	}
	printf("Class average grade: %.2lf\n", total_average / CSIZE);
}

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