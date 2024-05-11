/* 6. a. Given the following typedef, declare a 10-element array of the
indicated structure. Then, using individual member assignment (or the string
equivalent), let the third element describe a Remarkatar lens with a focal
length of 500 mm and an aperture of f/2.0. */
#include <string.h>

typedef struct lens { /* lens descriptor */
	float foclen;	  /* focal length,mm */
	float fstop;	  /* aperture */
	char brand[30];	  /* brand name */
} LENS;

int main(void) {
	LENS lens[10];
	lens[2].foclen = 500;
	lens[2].fstop = 2.0;
	strcpy(lens[2].brand, "Remarkatar");
}

/* b. Repeat part a., but use an initialization list with a designated
initializer in the declaration rather than using separate assignment statements
for each member */
LENS lens[10] = {[2] = {.foclen = 500, .fstop = 2.0, .brand = ""}};