#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;

    int left_part = x >> (w - n - 1) >> 1;
    int right_part = x << n;
    return left_part | right_part;
}

int main() {
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
}