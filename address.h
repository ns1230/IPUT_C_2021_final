/*
 * File: address.h
 * Description: Contains the structure definition for an address and function declarations used in the address book program.
 */


#include<stdio.h>
typedef struct address {
	int number;
	char name[30];
	char name_furikana[60];
	char zip_code[10];
	char address[100];
	char address_furikana[200];
} ADDRESS;
extern int readAddress(ADDRESS address[]); 
extern void writeAddress(int count, ADDRESS address[]); 
extern void sort(int count, ADDRESS address[]); 
extern int add(int count, ADDRESS address[]); 
extern int delete (int count, ADDRESS address[]);
extern void writeResult(int count, ADDRESS address[]); 
extern void write(FILE* out, int count, ADDRESS address[]); 
extern void renumbering(int count, ADDRESS address[]);
