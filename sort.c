#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "address.h"

void sort(int count, ADDRESS address[]) {
	int command;
	ADDRESS temporary;
	int i, j;
	printf(" Enter the key for sort ：\n");
	printf("1: Name\n");
	printf("2: Furigana of the name\n");
	printf("3: Post address\n");
	printf("4: Address\n");
	printf("5: Furigana of the address\n");
	printf(">");
	scanf("%d", &command);
	if (command == 1) {
		for (i = 0; i < count - 1; i++) {
			for (j = count - 2; j >= i; j--) {
				if (strcmp(address[j].name, address[j + 1].name) > 0) {
					temporary = address[j];
					address[j] = address[j + 1];
					address[j + 1] = temporary;
				}
			}
		}
		renumbering(count, address);
	}
	else if (command == 2) {
		for (i = 0; i < count - 1; i++) {
			for (j = count - 2; j >= i; j--) {
				if (strcmp(address[j].name_furikana, address[j + 1].name_furikana) > 0) {
					temporary = address[j];
					address[j] = address[j + 1];
					address[j + 1] = temporary;
				}
			}
		}
		renumbering(count, address);
	}
	else if (command == 3) {
		for (i = 0; i < count - 1; i++) {
			for (j = count - 2; j >= i; j--) {
				if (strcmp(address[j].zip_code, address[j + 1].zip_code) > 0) {
					temporary = address[j];
					address[j] = address[j + 1];
					address[j + 1] = temporary;
				}
			}
		}
		renumbering(count, address);
	}
	else if (command == 4) {
		for (i = 0; i < count - 1; i++) {
			for (j = count - 2; j >= i; j--) {
				if (strcmp(address[j].address, address[j + 1].address) > 0) {
					temporary = address[j];
					address[j] = address[j + 1];
					address[j + 1] = temporary;
				}
			}
		}
		renumbering(count, address);
	}
	else if (command == 5) {
		for (i = 0; i < count - 1; i++) {
			for (j = count - 2; j >= i; j--) {
				if (strcmp(address[j].address_furikana, address[j + 1].address_furikana) > 0) {
					temporary = address[j];
					address[j] = address[j + 1];
					address[j + 1] = temporary;
				}
			}
		}
		renumbering(count, address);
	}
	return;
}
