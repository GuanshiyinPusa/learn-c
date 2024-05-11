/* What’s wrong with this attempted declaration of a character string?
int main(void)
{
char name[] = {'F', 'e', 's', 's' };
...
} */
char name[] = {'F', 'e', 's', 's'};		   // There is no '\0' at the end of the
										   // char array
char name1[] = {'F', 'e', 's', 's', '\0'}; // this should be correct
