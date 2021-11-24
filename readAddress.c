#define _CRT_SECURE_NO_WARNINGS
#include "address.h"
#include <stdio.h>

int readAddress(ADDRESS address[]) {
    FILE* in;
    int num;
    int count;
    char name[30];
    char nameKana[60];
    char post[10];
    char uaddress[100];
    char uaddressKana[200];
    char c;

    in = fopen("address", "r");

    count = 0;
   
    if (in == NULL) {
        perror("Error opening file"); // print error
        return(-1);
    }

    for (int i = 0; i < 101; i++) {
        fscanf(in, "%d", &num);
        address[i].number = num;

        fscanf(in, "%s", &name);
        strcpy(address[i].name, name);

        fscanf(in, "%s", &nameKana);
        strcpy(address[i].name_furikana, nameKana);

        fscanf(in, "%s", &post);
        strcpy(address[i].zip_code, post);

        fscanf(in, "%s", &uaddress);
        strcpy(address[i].address, uaddress);

        fscanf(in, "%s", &uaddressKana);
        strcpy(address[i].address_furikana, uaddressKana);

        count++;
    }

    fclose(in);
    count = count - 1;
    return count;
}
