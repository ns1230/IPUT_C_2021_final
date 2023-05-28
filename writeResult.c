/*
 * File: writeResult.c
 * Description: Contains the implementation of the writeResult function, which writes the address entries to a file named "result".
 */

#define _CRT_SECURE_NO_WARNINGS
#include "address.h"
#include <stdio.h>

void writeResult(int count, ADDRESS address[]) {
    FILE* out;

    out = fopen("result", "w");
    write(out, count, address);
}
