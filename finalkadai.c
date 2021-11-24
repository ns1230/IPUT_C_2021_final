#define _CRT_SECURE_NO_WARNINGS
#define MAX 200
#include <stdio.h>
#include <string.h>
#include "address.h"

int main(void) {
	ADDRESS address[MAX];
	int count = 0;
	int flag = 0; /* 0: ソ ー ト 、 追 加 、 削 除 未 実 施 , 1: 実 施 済 */
	int command = 0;
	char string_command[10] = "y";
	while (1) {
		printf("\n ------------------------------------\n");
		printf("MENU \n");
		printf("1: 住 所 録 読 込\n");
		printf("2: 住 所 録 上 書\n");
		printf("3: ソ ー ト\n");
		printf("4: 追 加\n");
		printf("5: 削 除\n");
		printf("6: 結 果 書 込 （ r e s u l t フ ァ イ ル へ 書 込 ） \n");
		printf("0: 終 了\n");
		printf("------------------------------------\n");
		printf(">");
		scanf("%d", &command);
		if (command == 1) {
			count = readAddress(address);
			flag = 0;
		}
		else if (command == 2) {
				if (flag == 0) {
					printf(" ソ ー ト 、 追 加 、 削 除 未 実 施 で す 。 上 書 は 行 い ま せ ん 。\n");
				}
				else { /* flag == 1 */
					printf(" 住 所 録 を 上 書 き し ま す 。 宜 し い で す か ？ (y / n )");
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
				printf(" 住 所 録 の 上 限 で す 。 こ れ 以 上 追 加 で き ま せ ん 。\n");
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
				printf(" ソ ー ト 、 追 加 、 削 除 未 実 施 で す 。 書 込 は 行 い ま せ ん 。\n");
			}
			else { /* flag == 1 */
				writeResult(count, address);
				flag = 0;
			}
		}
		else {
			break; /* 無 限 ル ー プ か ら 脱 出 */
		}
	}
	return 0;
}