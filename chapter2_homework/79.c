#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

int mul3div4(int x) {
    x = (x << 1)  + x;
    int sigmask = x & INT_MIN;
    int bias = (1 << 2) - 1;
    sigmask && (x = x + bias);
    return x >> 2; 
}

int main(int argc, char const *argv[])
{
    assert(mul3div4(4) == 3);
    assert(mul3div4(INT_MAX) == INT_MAX * 3 / 4);
    assert(mul3div4(INT_MIN) == INT_MIN * 3 / 4);
    return 0;
}
