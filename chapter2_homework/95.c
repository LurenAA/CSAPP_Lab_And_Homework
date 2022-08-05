#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if(!(exp ^ 0xff) && frac)
        return f;
    
    unsigned rest = f & 0x7fffffff;
    int addition = (frac & 0x3) == 0x3;

    if(!exp) {
        frac = frac >> 1;
        frac += addition;
    } else if (exp == 1) {
        rest = rest >> 1;
        rest += addition;
        exp = rest >> 23 & 0xFF;
        frac = rest & 0x7fffff;
    } else {
        exp = exp - 1;
    }

    return ((sig) << 31) | (exp << 23) | frac; 
}

int main(int argc, char const *argv[])
{
    float_bits x = (unsigned)0x4640E400;
    printf("%.8x, %f\n", x, *((float*)&x));
    float_bits xn = float_half(x);
    printf("%.8x, %f\n", xn, *((float*)&xn));
    return 0;
}
