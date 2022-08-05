#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

int divide_power2(int x, int k) {
    int sigmask = x & INT_MIN;
    int bias = (1 << k) - 1;
    sigmask && (x = x + bias);
    return x >> k;
}

int main(int argc, char const *argv[])
{
    assert(divide_power2(10, 2) == 2);
    assert(divide_power2(-10, 2) == -2);
    return 0;
}
