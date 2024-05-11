// A text file holds information about a softball team. Each line has data
// arranged as follows:
// 4 Jessie Joybat 5 2 1 1
// The first item is the player’s number, conveniently in the range 0–18. The
// second item is the player’s first name, and the third is the player’s last
// name. Each name is a single word. The next item is the player’s official
// times at bat, followed by the number of hits, walks, and runs batted in
// (RBIs). The file may contain data for more than one game, so the same player
// may have more than one line of data, and there may be data for other players
// between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and last
// names, the at bats, hits, walks, and RBIs (runs batted in), and the batting
// average (to be calculated later). You can use the player number as an array
// index. The program should read to end- of-file, and it should keep cumulative
// totals for each player. The world of baseball statistics is an involved one.
// For example, a walk or reaching base on an error doesn’t count as an at-bat
// but could possibly produce an RBI. But all this program has to do is read and
// process the data file, as described next, without worrying about how
// realistic the data is. The simplest way for the program to proceed is to
// initialize the structure contents to zeros, read the file data into temporary
// variables, and then add them to the contents of the corresponding structure.
// After the program has finished reading the file, it should then calculate the
// batting average for each player and store it in the corresponding structure
// member. The batting average is calculated by dividing the cumulative number
// of hits for a player by the cumulative number of at-bats; it should be a
// floating-point calculation. The program should then display the cumulative
// data for each player along with a line showing the combined statistics for
// the entire team
#include <stdio.h>

struct player {
	char first_name[20];
	char last_name[20];
	int at_bats;
	int hits;
	int walks;
	int rbis;
	double batting_average;
};

struct player team[19] = {0};

int main(void) {
	FILE *file = fopen("softball.txt", "r");
	if (!file) {
		printf("Failed to open file\n");
		return 1;
	}

	int number;
	while (fscanf(
			   file, "%d %s %s %d %d %d %d", &number, team[number].first_name,
			   team[number].last_name, &team[number].at_bats,
			   &team[number].hits, &team[number].walks,
			   &team[number].rbis) != EOF) {
		team[number].batting_average =
			(double)team[number].hits / team[number].at_bats;
	}

	fclose(file);

	int total_at_bats = 0, total_hits = 0, total_walks = 0, total_rbis = 0;
	for (int i = 0; i < 19; i++) {
		printf("Player %d: %s %s\n", i, team[i].first_name, team[i].last_name);
		printf("At bats: %d\n", team[i].at_bats);
		printf("Hits: %d\n", team[i].hits);
		printf("Walks: %d\n", team[i].walks);
		printf("RBIs: %d\n", team[i].rbis);
		printf("Batting average: %.2f\n\n", team[i].batting_average);

		total_at_bats += team[i].at_bats;
		total_hits += team[i].hits;
		total_walks += team[i].walks;
		total_rbis += team[i].rbis;
	}

	printf("Team totals:\n");
	printf("At bats: %d\n", total_at_bats);
	printf("Hits: %d\n", total_hits);
	printf("Walks: %d\n", total_walks);
	printf("RBIs: %d\n", total_rbis);
	printf("Batting average: %.2f\n", (double)total_hits / total_at_bats);

	return 0;
}