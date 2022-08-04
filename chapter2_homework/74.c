#include <stdio.h>
#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y){
    int sigmask = INT_MIN;
    int sum = x + y;
    int pos_over = !(x & sigmask) && (y & sigmask) && (sum & sigmask);
    int neg_over = (x & sigmask) && !(y & sigmask) && !(sum & sigmask);
    int int_min_over = !(x ^ INT_MIN) && !(y & sigmask);
    return !(pos_over | neg_over | int_min_over);
}

int main(int argc, char const *argv[])
{
    assert(!tsub_ok(INT_MAX, INT_MIN));
    assert(!tsub_ok(INT_MIN, INT_MAX));
    assert(!tsub_ok(0x00, INT_MIN));
    assert(tsub_ok(0x00, 0x00));
    return 0;
}
