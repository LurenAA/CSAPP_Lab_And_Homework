#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

typedef enum
{
    NEG,
    ZERO,
    POS,
    OTHER
} range_t;

range_t find_range(float x)
{
    range_t result;
    range_t n = NEG, z = ZERO, p = POS, o = OTHER;
    asm(
        "vxorps %%xmm1, %%xmm1, %%xmm1\n\t"
        "vucomiss %%xmm1, %%xmm0\n\t"
        "cmove %[z], %[val]\n\t"
        "cmovb %[n], %[val]\n\t"
        "cmova %[p], %[val]\n\t"
        "cmovp %[o], %[val]\n\t"
        : [val] "=r" (result), [n] "+rm" (n), [z] "+rm" (z),[p] "+rm" (p),[o] "+rm" (o)
        :
        : "%xmm1", "%xmm0");

    return result;
}

int main()
{
    range_t n = NEG, z = ZERO, p = POS, o = OTHER;
    assert(o == find_range(0.0 / 0.0));
    assert(n == find_range(-2.3));
    assert(z == find_range(0.0));
    assert(p == find_range(3.33));
}