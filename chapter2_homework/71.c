#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    int max_num = 3;
    return (int)word << ((max_num - bytenum) << 3) >> (max_num << 3);
}

int main(int argc, char const *argv[])
{
    int a1 = xbyte(0x00ff0011, 2);
    assert(a1 == 0xffffffff);
    int a2 = xbyte(0xfff10000, 2);
    assert(a2 == 0xfffffff1);
    return 0;
}
