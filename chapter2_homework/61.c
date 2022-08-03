#include <stdio.h>

int main(){
    unsigned x = 0xff11ffff;
    unsigned high_addr_mask = (0xFF) << ((sizeof(int) - 1) << 3);
    unsigned result1 = !(x ^ (~0));
    unsigned result2 = !(x ^ 0);
    unsigned result3 = !((x & 0xFF) ^ 0xFF);
    unsigned result4 = !(x & (high_addr_mask) ^ 0);
    unsigned result = result1 || result2 || result3 || result4;
    printf("%x\n", result);
}