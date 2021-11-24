#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <string.h>
#include "address.h"

int main(void) {
	ADDRESS address[MAX];
	int count = 0;
	int flag = 0; /* 0: �\ �[ �g �A �� �� �A �� �� �� �� �{ , 1: �� �{ �� */
	int command = 0;
	char string_command[10] = "y";
	while (1) {
		printf("\n ------------------------------------\n");
		printf("MENU \n");
		printf("1: �Z �� �^ �� ��\n");
		printf("2: �Z �� �^ �� ��\n");
		printf("3: �\ �[ �g\n");
		printf("4: �� ��\n");
		printf("5: �� ��\n");
		printf("6: �� �� �� �� �i r e s u l t �t �@ �C �� �� �� �� �j \n");
		printf("0: �I ��\n");
		printf("------------------------------------\n");
		printf(">");
		scanf("%d", &command);
		if (command == 1) {
			count = readAddress(address);
			flag = 0;
		}
		else if (command == 2) {
				if (flag == 0) {
					printf(" �\ �[ �g �A �� �� �A �� �� �� �� �{ �� �� �B �� �� �� �s �� �� �� �� �B\n");
				}
				else { /* flag == 1 */
					printf(" �Z �� �^ �� �� �� �� �� �� �� �B �X �� �� �� �� �� �H (y / n )");
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
				printf(" �Z �� �^ �� �� �� �� �� �B �� �� �� �� �� �� �� �� �� �� �� �B\n");
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
				printf(" �\ �[ �g �A �� �� �A �� �� �� �� �{ �� �� �B �� �� �� �s �� �� �� �� �B\n");
			}
			else { /* flag == 1 */
				writeResult(count, address);
				flag = 0;
			}
		}
		else {
			break; /* �� �� �� �[ �v �� �� �E �o */
		}
	}
	return 0;
}