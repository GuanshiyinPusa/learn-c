/* Function Pointer */
/* void (*pf)(char *); // pf a pointer-to-function
void *pf(char *);	// pf a function that returns a pointe */

// The name of the function is the address of the function
/* void ToUpper(char *);
void ToLower(char *);
int round(double);
void (*pf)(char *);
pf = ToUpper;	// valid, ToUpper is address of the function
pf = ToLower;	// valid, ToLower is address of the function
pf = round;		// invalid, round is the wrong type of function
pf = ToLower(); // invalid, ToLower() is not an addres */

// Use function pointer
/* void ToUpper(char *);
void ToLower(char *);
void (*pf)(char *);
char mis[] = "Nina Metier";
pf = ToUpper;
(*pf)(mis); // apply ToUpper to mis (syntax 1)  Bell lab way
pf = ToLower;
pf(mis); // apply ToLower to mis (syntax 2) Berkeley way */

// void show(void (*fp)(char *), char *str);
// show(ToLower, mis); /* show() uses ToLower() function: fp = ToLower */
// show(pf, mis);		/* show() uses function pointed to by pf: fp = pf */
// void show(void (*fp)(char *), char *str) {
//  (*fp)(str); /* apply chosen function to str */
//	puts(str);	/* display result */
// }

// func_ptr.c -- uses function pointers
// Another way:
// typedef void (*V_FP_CHARP)(char *);
// void show (V_FP_CHARP fp, char *);
// V_FP_CHARP pfun;

// V_FP_CHARP arpf[4] = {ToUpper, ToLower, Transpose, Dummy};
// index = showmenu();
// while (index >= 0 && index <= 3) {
// 	strcpy(copy, line);		 /* make copy for show() */
//  show(arpf[index], copy); /* use selected function */
//  index = showmenu();
//}
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define LEN 81
char *s_gets(char *st, int n);
char showmenu(void);
void eatline(void); // read through the end of the line
void show(void (*fp)(char *), char *str);
void ToUpper(char *);	// convert string to uppercase
void ToLower(char *);	// convert string to uppercase
void Transpose(char *); // transpose cases
void Dummy(char *);		// leave string unaltered

int main(void) {
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char *); // points a function having a
						  // char * argument and no
						  // return value
	puts("Enter a string (empty line to quit):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0') {
		while ((choice = showmenu()) != 'n') {
			switch (choice) // switch sets pointer
			{
			case 'u':
				pfun = ToUpper;
				break;
			case 'l':
				pfun = ToLower;
				break;
			case 't':
				pfun = Transpose;
				break;
			case 'o':
				pfun = Dummy;
				break;
			}
			strcpy(copy, line); // make copy for show()
			show(pfun, copy);	// use selected function
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");
	return 0;
}

char showmenu(void) {
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase\tl) lowercase\t");
	puts("t) transposed case\to) original case");
	puts("n) next string");
	ans = getchar();	// get response
	ans = tolower(ans); // convert to lowercase
	eatline();
	// dispose of rest of line
	while (strchr("ulton", ans) == NULL) {
		puts("Please enter a u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void) {
	while (getchar() != '\n')
		continue;
}

void ToUpper(char *str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char *str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char *str) {
	while (*str) {
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char *str) {
	// leaves string unchanged
}

void show(void (*fp)(char *), char *str) {
	(*fp)(str); // apply chosen function to str
	puts(str);	// display result
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n'); // look for newline
		if (find)				 // if the address is not NULL,
			*find = '\0';		 // place a null character there
		else
			while (getchar() != '\n')
				continue; // dispose of rest of line
	}
	return ret_val;
}