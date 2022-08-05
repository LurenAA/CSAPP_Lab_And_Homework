#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

typedef unsigned float_bits;

int float_f2i(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0x7f;
    
    int num;

    if(exp >= 0 && exp < bias) 
        num = 0;
    else if(exp >= 31 + bias) 
        num = 0x80000000;
    else {
        int E = exp - bias;
        int M = frac | 0x800000;
        if (E > 23)
            num = M << (E - 23);
        else 
            num = M >> (23 - E);
    }

    return sig? -num : num;
}