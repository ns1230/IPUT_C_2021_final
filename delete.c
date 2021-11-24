#define _CRT_SECURE_NO_WARNINGS
#include "address.h"
#include <stdio.h>

int delete (int count, ADDRESS address[]) {
    int accnum;

    printf("Type the number of the address you want to delete: ");
    scanf("%d", &accnum);
    for (int i = accnum - 1; i < count; i++) {
        address[i] = address[i + 1];
    }
    count = count - 1;
    renumbering(count, address);
    return count;
}