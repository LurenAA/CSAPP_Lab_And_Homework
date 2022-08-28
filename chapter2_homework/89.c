#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int E(double dx, double dz)
{
    double zdiv = dz / dz;
    double xdiv = dx / dx;
    return xdiv == zdiv;
}

int main()
{
    int x = 30;
    double dx = (double)x;
    assert(!E(dx, (double)(int)0));
    return 0;
}