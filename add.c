/*
 * File: add.c
 * Description: Contains the implementation of the add function, which adds a new address entry to the address book.
 */

#define _CRT_SECURE_NO_WARNINGS
#include "address.h"


int add(int count, ADDRESS address[]) {
    int num;
    char name[30];
    char nameKana[60];
    char post[10];
    char uaddress[100];
    char uaddressKana[200];

    printf("---- Adding a new address ----¥n");
    printf("What is the name in Kanji?: ");
    scanf("%s", name);
    printf("What is the name in Katakana?: ");
    scanf("%s", nameKana);
    printf("WHat is the zip code?: ");
    scanf("%s", post);
    printf("WHat is the address?: ");
    scanf("%s", uaddress);
    printf("What is the address in Katakana?: ");
    scanf("%s", uaddressKana);
  
    address[count].number = count+1;
    strcpy(address[count].name, name);
    strcpy(address[count].name_furikana, nameKana);
    strcpy(address[count].zip_code, post);
    strcpy(address[count].address, uaddress);
    strcpy(address[count].address_furikana, uaddressKana);

    count++;
    return count;
}
