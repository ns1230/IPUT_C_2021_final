#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "address.h"

void sort(int count, ADDRESS address[]) {
	int command;
	ADDRESS temporary;
	int i, j;
	printf(" ソ ー ト す る キ ー を 入 力 ：\n");
	printf("1: 名 前\n");
	printf("2: 名 前 の フ リ カ ナ\n");
	printf("3: 郵 便 番 号\n");
	printf("4: 住 所\n");
	printf("5: 住 所 の フ リ カ ナ\n");
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