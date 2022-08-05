#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

int A(int k)
{
    return -1 << k;
}

int B(int k, int j)
{
    return ((1 << k) - 1) << j;
}

int main(int argc, char const *argv[])
{
    assert(A(8) == 0xFFFFFF00);
    assert(B(16, 8) == 0x00FFFF00);
    return 0;
}
