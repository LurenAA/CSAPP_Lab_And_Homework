#include <stdio.h>

int int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = (long long)1 << 32;

    return set_msb && !beyond_msb;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", int_size_is_32());
    return 0;
}
