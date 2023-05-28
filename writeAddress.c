/*
 * File: writeAddress.c
 * Description: Contains the implementation of the writeAddress function, which writes the address entries to a file named "address".
 */

#define _CRT_SECURE_NO_WARNINGS
#include "address.h"
#include <stdio.h>

void writeAddress(int count, ADDRESS address[]) {
    FILE* out;

    out = fopen("address", "w");
    write(out, count, address);
}
