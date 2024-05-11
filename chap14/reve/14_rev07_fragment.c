// Consider the following programming fragment :
// struct name {
// 	char first[20];
// 	char last[20];
// };

// struct bem {
// 	int limbs;
// 	struct name title;
// 	char type[30];
// };
// struct bem *pb;
// struct bem deb = {6, {"Berbnazel", "Gwolkapwolk"}, "Arcturan"};
// pb = &deb;
/* a. What would each of the following statements print? */
// printf("%d\n", deb.limbs);	  // 6
// printf("%s\n", pb->type);	  // Arcturan
// printf("%s\n", pb->type + 2); // cturan
// b. How could you represent "Gwolkapwolk" in structure notation (two ways)?
// deb.title.last;
// pb->title.last;

/* c. Write a function that takes the address of a bem structure as its argument
and prints the contents of that structure in the form shown here (assume that
the structure template is in a file called starfolk.h): Berbnazel Gwolkapwolk is
a 6-limbed Arcturan */
/* void print_bem(struct bem *bem_sample_ptr) {
	printf(
		"%s %s is a %d-limbed %s", bem_sample_ptr->title.first,
		bem_sample_ptr->title.last, bem_sample_ptr->limbs,
		bem_sample_ptr->type);
} */