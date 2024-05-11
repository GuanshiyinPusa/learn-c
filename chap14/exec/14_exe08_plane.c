// The Colossus Airlines fleet consists of one plane with a seating capacity
// of 12. It makes one flight daily. Write a seating reservation program with
// the following features:
// a. The program uses an array of 12 structures. Each structure should hold a
// seat identification number, a marker that indicates whether the seat is
// assigned, the last name of the seat holder, and the first name of the seat
// holder.
// b. The program displays the following menu:
// To choose a function, enter its letter label:
// a) Show number of empty seats
// b) Show list of empty seats
// c) Show alphabetical list of seats
// d) Assign a customer to a seat assignment
// e) Delete a seat assignment
// f) Quit
// c. The program successfully executes the promises of its menu. Choices d) and
// e) require additional input, and each should enable the user to abort an
// entry.
// d. After executing a particular function, the program shows the menu
// again, except for choice f).
// e. Data is saved in a file between runs. When the program is restarted, it
// first loads in the data, if any, from the file.
#include <stdio.h>
#include <string.h>

#define SEAT_COUNT 12
#define NAME_LENGTH 40

typedef struct {
	int id;
	int is_assigned;
	char last_name[NAME_LENGTH];
	char first_name[NAME_LENGTH];
} Seat;

Seat seats[SEAT_COUNT];

void show_menu() {
	printf("To choose a function, enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
}

void show_empty_seats() {
	int count = 0;
	for (int i = 0; i < SEAT_COUNT; i++) {
		if (!seats[i].is_assigned) {
			count++;
		}
	}
	printf("Number of empty seats: %d\n", count);
}

void show_list_empty_seats() {
	printf("List of empty seats:\n");
	for (int i = 0; i < SEAT_COUNT; i++) {
		if (!seats[i].is_assigned) {
			printf("Seat ID: %d\n", seats[i].id);
		}
	}
}

void show_list_seats() {
	printf("Alphabetical list of seats:\n");
	// Simple bubble sort for demonstration purposes
	for (int i = 0; i < SEAT_COUNT - 1; i++) {
		for (int j = 0; j < SEAT_COUNT - i - 1; j++) {
			if (strcmp(seats[j].last_name, seats[j + 1].last_name) > 0) {
				Seat temp = seats[j];
				seats[j] = seats[j + 1];
				seats[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < SEAT_COUNT; i++) {
		if (seats[i].is_assigned) {
			printf(
				"Seat ID: %d, Name: %s, %s\n", seats[i].id, seats[i].last_name,
				seats[i].first_name);
		}
	}
}

void assign_seat() {
	int id;
	printf("Enter seat ID to assign: ");
	scanf("%d", &id);
	if (id < 1 || id > SEAT_COUNT || seats[id - 1].is_assigned) {
		printf("Invalid seat ID.\n");
		return;
	}
	seats[id - 1].is_assigned = 1;
	printf("Enter last name: ");
	scanf("%s", seats[id - 1].last_name);
	printf("Enter first name: ");
	scanf("%s", seats[id - 1].first_name);
}

void delete_seat() {
	int id;
	printf("Enter seat ID to delete: ");
	scanf("%d", &id);
	if (id < 1 || id > SEAT_COUNT || !seats[id - 1].is_assigned) {
		printf("Invalid seat ID.\n");
		return;
	}
	seats[id - 1].is_assigned = 0;
}

int main() {
	FILE *file = fopen("seats.dat", "rb");
	if (file) {
		fread(seats, sizeof(Seat), SEAT_COUNT, file);
		fclose(file);
	} else {
		for (int i = 0; i < SEAT_COUNT; i++) {
			seats[i].id = i + 1;
			seats[i].is_assigned = 0;
		}
	}

	char choice;
	do {
		show_menu();
		scanf(" %c", &choice);
		switch (choice) {
		case 'a':
			show_empty_seats();
			break;
		case 'b':
			show_list_empty_seats();
			break;
		case 'c':
			show_list_seats();
			break;
		case 'd':
			assign_seat();
			break;
		case 'e':
			delete_seat();
			break;
		}
	} while (choice != 'f');

	file = fopen("seats.dat", "wb");
	fwrite(seats, sizeof(Seat), SEAT_COUNT, file);
	fclose(file);

	return 0;
}