#define _CRT_SECURE_NO_WARNINGS
#include "address.h"
#include <stdio.h>

void writeResult(int count, ADDRESS address[]) {
    FILE* out;

    out = fopen("result", "w");
    write(out, count, address);
}
