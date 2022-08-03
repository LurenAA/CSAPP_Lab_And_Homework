#include <stdio.h>

int any_odd_one(unsigned x) {
    int mask = 0b01010101;
    mask = (mask << 8) | mask;
    mask = (mask << 16) | mask;
    return !!(x & mask);
}

int main(){
    printf("%d\n", any_odd_one(0b10));
}