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
    asm(
        "vxorps %%xmm1, %%xmm1, %%xmm1\n\t"
        "vucomiss %%xmm1, %%xmm0\n\t"
        "jp .OTHER\n\t"
        "je .ZERO\n\t"
        "jb .NEG\n\t"
        "movl $2, %[val]\n\t"
        "jmp .DONE\n\t"
        ".OTHER:\n\t"
        "movl $3, %[val]\n\t"
        "jmp .DONE\n\t"
        ".ZERO:\n\t"
        "movl $1, %[val]\n\t"
        "jmp .DONE\n\t"
        ".NEG:\n\t"
        "movl $0, %[val]\n\t"
        ".DONE: \n\t"
        : [val] "=r" (result)
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