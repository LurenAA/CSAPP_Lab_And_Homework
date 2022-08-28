#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int w = 8 * sizeof(int);
    int mask = (1 << (w - k)) - 1;
    return xsra & mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned)x >> k;

    int w = 8 * sizeof(int);
    int mask = ~((1 << (w - k)) - 1);
    int sign = x >> (w - 1);
    if(sign) 
        xsrl |= mask;
    return xsrl;
}

int main(){
    int test_times = 100;
    int k = 4;
    unsigned test_val = 0;
    int test_val_int = 0;
    for(int i = 0; i < test_times; ++i) {
        srand(i);
        test_val = (unsigned)rand();
        assert((test_val >> k) == srl(test_val, k));

        test_val_int = rand();
        assert((test_val_int >> k) == sra(test_val_int, k));
    }
}