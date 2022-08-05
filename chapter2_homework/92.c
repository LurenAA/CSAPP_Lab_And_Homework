#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if(!(exp ^ 0xff) && frac)
        return f;
    return ((~sign) << 31) | (exp << 23) | frac;  
}

int main(int argc, char const *argv[])
{
    float_bits x = (unsigned)0x4640E400;
    printf("%.8x, %f\n", x, *((float*)&x));
    float_bits xn = float_negate(x);
    printf("%.8x, %f\n", xn, *((float*)&xn));
    return 0;
}
