#include <stdio.h>

unsigned rotate_left(unsigned x, int n){
    int w = sizeof(unsigned);
    unsigned rm1 = x >> ((w << 3) - n);
    return rm1 | (x << n);
}

int main() {
    unsigned x = 0x12345678;
    printf("%.8x\n", rotate_left(x, 4));
    printf("%.8x\n", rotate_left(x, 20));
}