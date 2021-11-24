#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "address.h"

void write(FILE* out, int count, ADDRESS address[]) {
    int num;

    for (int i = 0; i < count; i++) {
        num = address[i].number;
        fprintf(out, "%d\n", num);
    
        fprintf(out, "%s\n", address[i].name);

        fprintf(out, "%s\n", address[i].name_furikana);

        fprintf(out, "%s\n", address[i].zip_code);

        fprintf(out, "%s\n", address[i].address);

        fprintf(out, "%s\n", address[i].address_furikana);
    }
}
