#include <stdio.h>
#include <limits.h>
#include <assert.h>

int saturating_add(int x, int y) {
    int x_plus_y = x + y;
    int sigmask = INT_MIN;

    int posover = !(x & sigmask) && !(y & sigmask) && (x_plus_y & INT_MIN);
    int negover = (x & sigmask) && (y & sigmask) && !(x_plus_y & INT_MIN);
    
    (posover) && (x_plus_y = INT_MAX);
    (negover) && (x_plus_y = INT_MIN);
    return x_plus_y;
}

int main(int argc, char const *argv[])
{
    assert(INT_MAX == saturating_add(0x7FFFFFFF,0X7FFFFFFF));   
    assert(INT_MIN == saturating_add(0x80000000,0X80000000));   
    return 0;
}
