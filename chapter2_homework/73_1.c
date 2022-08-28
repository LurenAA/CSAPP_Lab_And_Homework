#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int res = x + y;
    int w = sizeof(int) << 3;
    int positive_overflow = !(x & (1 << w - 1)) && !(y & (1 << w - 1)) && (x + y & (1 << w - 1));
    int negative_overflow = (x & (1 << w - 1)) && (y & (1 << w - 1)) && !(x + y & (1 << w - 1));

    positive_overflow && (res = INT_MAX);
    negative_overflow && (res = INT_MIN);

    return res;
}

int main()
{
    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
}