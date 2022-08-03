#include <stdio.h>

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + (x && 1);
}

int main(int argc, char const *argv[])
{
    printf("%.8x\n", leftmost_one(0xFF000000));
    printf("%.8x\n", leftmost_one(0x000FF000));
    return 0;
}
