// Suppose you have these statements in a program:
#include <stdio.h>
FILE *fp1, *fp2;
char ch;
fp1 = fopen("terky", "r");
fp2 = fopen("jerky", "w");
// Also, suppose that both files were opened successfully. Supply the missing
// arguments in the following function calls:
// a. ch = getc();
// b. fprintf(,"%c\n", );
// c. putc( , );
// d. fclose(); /* close the terky file */

// a. ch = getc(fp1);
// b. fprintf(fp2,"%c"\n",ch);
// c. putc(ch,fp2);
// d. fclose(fp1); /* close the terky file */