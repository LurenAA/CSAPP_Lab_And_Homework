#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

int threeforths(int x)
{
    int mask = INT_MIN & x;
    int l = x & 0x3;
    int f = x & ~0x3;
    int bias = (1 << 2) - 1;
    int res_f = ((f >> 2) << 1) + (f >> 2);
    int res_l = (l << 1) + l;
    mask && (res_l = res_l + bias);
    res_l = (res_l >> 2);
    int res = res_f + res_l;
    return res;
}

int main(int argc, char const *argv[])
{
    assert(threeforths(8) == 6);
    assert(threeforths(9) == 6);
    assert(threeforths(10) == 7);
    assert(threeforths(11) == 8);
    assert(threeforths(12) == 9);

    assert(threeforths(-8) == -6);
    assert(threeforths(-9) == -6);
    assert(threeforths(-10) == -7);
    assert(threeforths(-11) == -8);
    assert(threeforths(-12) == -9);
    return 0;
}
