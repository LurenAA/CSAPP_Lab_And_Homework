#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){
    unsigned char* ptr = (unsigned char*)&x;
    ptr[i] = b;
    return x;
}

void main(){
    unsigned x1 = replace_byte(0x12345678, 2, 0xAB);
    unsigned x2 = replace_byte(0x12345678, 0, 0xAB);
    printf("0x%x 0x%x\n", x1, x2);
}