#include <stdio.h>

int main() {
    unsigned int x = 0x12345678;
    unsigned int byte = *(unsigned char*)&x;

    if(byte == 0x12) {
        printf("Big endian.\n");
    } else {
        printf("Little endian.\n");
    }

    return 0;
}