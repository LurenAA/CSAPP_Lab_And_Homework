#include <stdio.h>

int is_little_endian(int x){
    unsigned char x_low_addr = ((unsigned char*)(&x))[0]; 
    return x_low_addr == (x & 0xFF);
}

void main(){
    printf("%d\n", is_little_endian(0x123456));
}