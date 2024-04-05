// Answer:
#include <stdio.h>
void showmenu(void); /* declare functions used */
int getchoice(int, int);

int main() {
	int res;

	showmenu();
	while ((res = getchoice(1, 4)) != 4) {
		printf("I like choice %d.\n", res);
		showmenu();
	}
	printf("Bye!\n");
	return 0;
}

void showmenu(void) {
	printf("PLease choose one of the following:\n");
	printf("1) copy files       2) move files\n");
	printf("3) remove files     4) quit\n");
	printf("Enter the number of your choice:\n");
}

int getchoice(int low, int high) {
	int ans;
	int good;
	good = scanf("%d", &ans);
	while (good == 1 && (ans < low || ans > high))
	// when the scanf reads a valid integer and the input is within the
	// bound
	{
		printf("%d is not a valid choice; try again\n", ans);
		showmenu();
		scanf("%d", &ans);
	}
	if (good != 1) {
		printf("Non-numeric input. ");
		ans = 4;
	}
	return ans;
}
