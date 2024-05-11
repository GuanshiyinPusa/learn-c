// Colossus Airlines (from exercise 8) acquires a second plane (same capacity)
// and expands its service to four flights daily (Flights 102, 311, 444, and
// 519). Expand the program to handle four flights. Have a top-level menu that
// offers a choice of flights and the option to quit. Selecting a particular
// flight should then bring up a menu similar to that of exercise 8. However,
// one new item should be added: confirming a seat assignment. Also, the quit
// choice should be replaced with the choice of exiting to the top-level menu.
// Each display should indicate which flight is currently being handled. Also,
// the seat assignment display should indicate the confirmation status.

#include <stdio.h>
#include <string.h>

#define SEAT_COUNT 12
#define FLIGHT_COUNT 4
#define NAME_LENGTH 40

typedef struct {
	int id;
	int is_assigned;
	int is_confirmed;
	char last_name[NAME_LENGTH];
	char first_name[NAME_LENGTH];
} Seat;

typedef struct {
	int number;
	Seat seats[SEAT_COUNT];
} Flight;

Flight flights[FLIGHT_COUNT] = {{102}, {311}, {444}, {519}};

void show_flight_menu() {
	printf("Choose a flight or quit:\n");
	for (int i = 0; i < FLIGHT_COUNT; i++) {
		printf("%d) Flight %d\n", i + 1, flights[i].number);
	}
	printf("%d) Quit\n", FLIGHT_COUNT + 1);
}

void show_seat_menu(int flight_index) {
	printf(
		"To choose a function for flight %d, enter its letter label:\n",
		flights[flight_index].number);
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Confirm a seat assignment\n");
	printf("g) Return to flight menu\n");
}

void show_empty_seats(Flight *flight) {
	int count = 0;
	for (int i = 0; i < SEAT_COUNT; i++) {
		if (!flight->seats[i].is_assigned) {
			count++;
		}
	}
	printf("Number of empty seats in flight %d: %d\n", flight->number, count);
}

void show_list_empty_seats(Flight *flight) {
	printf("List of empty seats in flight %d:\n", flight->number);
	for (int i = 0; i < SEAT_COUNT; i++) {
		if (!flight->seats[i].is_assigned) {
			printf("Seat ID: %d\n", flight->seats[i].id);
		}
	}
}

void show_list_seats(Flight *flight) {
	printf("Alphabetical list of seats in flight %d:\n", flight->number);
	// Simple bubble sort for demonstration purposes
	for (int i = 0; i < SEAT_COUNT - 1; i++) {
		for (int j = 0; j < SEAT_COUNT - i - 1; j++) {
			if (strcmp(
					flight->seats[j].last_name,
					flight->seats[j + 1].last_name) > 0) {
				Seat temp = flight->seats[j];
				flight->seats[j] = flight->seats[j + 1];
				flight->seats[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < SEAT_COUNT; i++) {
		if (flight->seats[i].is_assigned) {
			printf(
				"Seat ID: %d, Name: %s, %s, %s\n", flight->seats[i].id,
				flight->seats[i].last_name, flight->seats[i].first_name,
				flight->seats[i].is_confirmed ? "Confirmed" : "Not confirmed");
		}
	}
}

void assign_seat(Flight *flight) {
	int id;
	printf("Enter seat ID to assign: ");
	scanf("%d", &id);
	if (id < 1 || id > SEAT_COUNT || flight->seats[id - 1].is_assigned) {
		printf("Invalid seat ID.\n");
		return;
	}
	flight->seats[id - 1].is_assigned = 1;
	printf("Enter last name: ");
	scanf("%s", flight->seats[id - 1].last_name);
	printf("Enter first name: ");
	scanf("%s", flight->seats[id - 1].first_name);
}

void delete_seat(Flight *flight) {
	int id;
	printf("Enter seat ID to delete: ");
	scanf("%d", &id);
	if (id < 1 || id > SEAT_COUNT || !flight->seats[id - 1].is_assigned) {
		printf("Invalid seat ID.\n");
		return;
	}
	flight->seats[id - 1].is_assigned = 0;
}

void confirm_seat(Flight *flight) {
	int id;
	printf("Enter seat ID to confirm: ");
	scanf("%d", &id);
	if (id < 1 || id > SEAT_COUNT || !flight->seats[id - 1].is_assigned) {
		printf("Invalid seat ID.\n");
		return;
	}
	flight->seats[id - 1].is_confirmed = 1;
}

int main() {
	FILE *file = fopen("flights.dat", "rb");
	if (file) {
		fread(flights, sizeof(Flight), FLIGHT_COUNT, file);
		fclose(file);
	} else {
		for (int i = 0; i < FLIGHT_COUNT; i++) {
			for (int j = 0; j < SEAT_COUNT; j++) {
				flights[i].seats[j].id = j + 1;
				flights[i].seats[j].is_assigned = 0;
			}
		}
	}

	int flight_choice;
	do {
		show_flight_menu();
		scanf("%d", &flight_choice);
		if (flight_choice < 1 || flight_choice > FLIGHT_COUNT + 1) {
			printf("Invalid choice.\n");
			continue;
		}
		if (flight_choice == FLIGHT_COUNT + 1) {
			break;
		}
		char seat_choice;
		do {
			show_seat_menu(flight_choice - 1);
			scanf(" %c", &seat_choice);
			switch (seat_choice) {
			case 'a':
				show_empty_seats(&flights[flight_choice - 1]);
				break;
			case 'b':
				show_list_empty_seats(&flights[flight_choice - 1]);
				break;
			case 'c':
				show_list_seats(&flights[flight_choice - 1]);
				break;
			case 'd':
				assign_seat(&flights[flight_choice - 1]);
				break;
			case 'e':
				delete_seat(&flights[flight_choice - 1]);
				break;
			case 'f':
				confirm_seat(&flights[flight_choice - 1]);
				break;
			case 'g':
				break;
			default:
				printf("Invalid choice.\n");
			}
		} while (seat_choice != 'g');
	} while (1);

	file = fopen("flights.dat", "wb");
	fwrite(flights, sizeof(Flight), FLIGHT_COUNT, file);
	fclose(file);

	return 0;
}