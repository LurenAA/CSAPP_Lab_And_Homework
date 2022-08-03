#include <stdio.h>

unsigned srl(unsigned x, int k){
    unsigned xsra = (int) x >> k;
    return xsra & ~(~0 << (sizeof(unsigned)* 8 - k));
}

int sra(int x, int k){
    int xsrl = (unsigned)x >> k;
    int mask = (~0 << (sizeof(unsigned)* 8 - k));
    int m = 1 << (sizeof(unsigned)* 8 - 1);
    mask &= !(m & x) - 1;
    return xsrl | mask;
}

int main(){
    unsigned srl1 = srl(-1, 8);
    printf("%.8x\n", srl1);
    int sra1 = sra(0xfff, 8);
    printf("%.8x\n", sra1);
}