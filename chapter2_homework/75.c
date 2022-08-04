#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

//solution https://github.com/agelessman/csapp-3e-solutions/blob/master/%E7%AC%AC%E4%BA%8C%E7%AB%A0%E7%AD%94%E6%A1%88/2.75.c
int signed_high_prod(int x, int y){
    int64_t x1 = (int64_t) x;
    int64_t y1 = (int64_t) y;
    int64_t mul = x1 * y1;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y){
    int res = signed_high_prod(x, y) + (x >> 31) *y + (y >> 31) *x;
    return res;
}

int main(int argc, char const *argv[])
{
    unsigned x1 = unsigned_high_prod(0xFF000000, 0xFF000000);
    unsigned x2 = (((uint64_t)0xFF000000* 0xFF000000) >> 32);
    assert(x1 == x2);
    return 0;
}
