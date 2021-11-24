#define _CRT_SECURE_NO_WARNINGS
#include "address.h"

void renumbering(int count, ADDRESS address[]) {
    for (int i = 0; i < count; i++) {
        address[i].number = i+1;
    }
}
