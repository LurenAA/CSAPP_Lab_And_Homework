#include <stdio.h>
#include <assert.h>

int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    int mask = ~((unsigned)-1 >> (w - n));
    return !(x & mask);
}

int main(int argc, char const *argv[])
{
    assert(fits_bits(0xFF, 8) == 1);
    assert(fits_bits(0xFF, 3) == 0);
    assert(fits_bits(0xFF, 13) == 1);
    return 0;
}
