#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int int_size_is_32() {
    int set_msb = 1 << 15 << 15 << 1;
    int tmp = (1 << 15 << 15);
    int beyond_msb = tmp << 2;

    return set_msb && !beyond_msb;
}

int main() {
    assert(int_size_is_32() == 1);
}