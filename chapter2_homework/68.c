#include <stdio.h>

int lower_one_mask(int n) {
    int mask = 1 << n;
    return mask - 1;
}

int main(int argc, char const *argv[])
{
    printf("%.8x\n", lower_one_mask(6));
    printf("%.8x\n", lower_one_mask(17));
    return 0;
}
