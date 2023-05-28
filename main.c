/*
 * File: main.c
 * Description: This file contains the main function that drives the address book program. It provides a menu-driven interface for managing address entries.
 *
 * The program uses the "address" structure defined in the "address.h" header file to store address information. It allows the user to perform various operations such as reading addresses from a file, updating addresses, sorting addresses, adding new addresses, deleting addresses, and writing the results to a file.
 *
 * The main function presents a menu to the user and takes input to execute the corresponding operation. It keeps track of the current number of addresses stored in the "address" array and a flag to indicate whether any updates have been made since the last write operation.
 *
 * The menu options include:
 * 1. Read Address: Reads address entries from a file and populates the "address" array.
 * 2. Update Address: Updates the address entries if any changes have been made since the last write operation.
 * 3. Sort: Sorts the address entries in ascending order based on a chosen sorting criterion.
 * 4. Add: Adds a new address entry to the "address" array if the limit has not been reached.
 * 5. Delete: Deletes an address entry from the "address" array based on the specified address number.
 * 6. Write the result to the result file: Writes the address entries to a file if any updates have been made since the last write operation.
 * 0. Done: Exits the program.
 *
 * The main function runs in an infinite loop until the user chooses to exit. It prompts the user for menu selection, performs the corresponding operation, and updates the flag and count variables accordingly.
 */

#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <string.h>
#include "address.h"

int main(void) {
	ADDRESS address[MAX];
	int count = 0;
	int flag = 0; /* 0: Have not done Sort, Add, or Delete, 1: Done */
	int command = 0;
	char string_command[10] = "y";
	while (1) {
		printf("\n ------------------------------------\n");
		printf("MENU \n");
		printf("1:Read Address\n");
		printf("2: Update Address\n");
		printf("3: Sort\n");
		printf("4: Add\n");
		printf("5: Delete\n");
		printf("6: Write the result to the result file\n");
		printf("0: Done\n");
		printf("------------------------------------\n");
		printf(">");
		scanf("%d", &command);
		if (command == 1) {
			count = readAddress(address);
			flag = 0;
		}
		else if (command == 2) {
				if (flag == 0) {
					printf("Have not done Sort, Add, or Delete. No updates done.\n");
				}
				else { /* flag == 1 */
					printf("Would you like to update the address? (y / n )");
					scanf("%s", string_command);
					if (strcmp(string_command, "y") == 0) {
						printf("DEBUG: Before writeAddress\n");
						printf("DEBUG: count = %d \n", count);
						writeAddress(count, address);
					}
					flag = 0;
				}
		}
		else if (command == 3) {
			sort(count, address);
			flag = 1;
		}
		else if (command == 4) {
			if (count >= MAX) {
				printf("Limit reached for the number of address. No more address can be added.\n");
			}
			else {
				count = add(count, address);
				flag = 1;
			}
		}
		else if (command == 5) {
			count = delete (count, address);
			flag = 1;
		}
		else if (command == 6) {
			if (flag == 0) {
				printf("Have not done Sort, Add, or Delete. Updating the file will not be done.\n");
			}
			else { /* flag == 1 */
				writeResult(count, address);
				flag = 0;
			}
		}
		else {
			break; /* escape the loop */
		}
	}
	return 0;
}
