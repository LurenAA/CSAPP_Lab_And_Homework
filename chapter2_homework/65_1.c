#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int odd_ones(unsigned x) {
    assert(sizeof(x) == 4);

    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 1;
}

int main() {
    assert(odd_ones(0x11111) == 1);
    assert(odd_ones(0x11111f) == 1);
}