#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + 1;
}

int main() {
    assert(leftmost_one(0xff00) == 0x8000);
    assert(leftmost_one(0x6600) == 0x4000);
}