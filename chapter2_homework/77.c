#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>

int A(int x) {
    return (x << 4) + x;
}

int B(int x) {
    return x - (x << 3);
}

int C(int x) {
    return (x << 6) - (x << 2);
}

int D(int x) {
    return (x << 4) - (x << 7);
}

int main(int argc, char const *argv[])
{
    int x = 1;
    assert(A(x) == 17);
    assert(B(x) == -7);
    assert(C(x) == 60);
    assert(D(x) == -112);
    return 0;
}
