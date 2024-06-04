// useheader.c -- use the names_st structure
#include "16_06_names_st.h"
#include <stdio.h>

// remember to link with names_st.c
// gcc 16_07_name_st.c 16_08_useheader.c
int main(void) {
	names candidate;

	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	printf(" to this program!\n");
	return 0;
}
