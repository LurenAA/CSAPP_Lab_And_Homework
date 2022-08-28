#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for(i = 0; i < len; ++i)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_float(float x) {
    show_bytes((byte_pointer)&x, 4);
}

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7fffff;
    if(exp == 0 ){
        frac <<= 1;
        if (frac & 0x800000)
        {
            frac &= 0x7fffff;
            exp++;
        }
    } else if (exp == 0xFF - 1) {
        /* twice to oo */
        exp = 0xFF;
        frac = 0;
   }  else {
        exp += 1;
    }
    return (sign << 31) | (exp << 23) | frac;
}

void main() {

}