#include <stdio.h>

void main(){
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int result = (x & 0xFF) + (y & ~0xFF);
    printf("%x\n", result); 
}