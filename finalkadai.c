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
