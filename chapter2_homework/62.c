#include <stdio.h>

unsigned int_shifts_are_ariththmetic(){
    int x = -1;
    x = x >> ((sizeof(int) - 1) << 3) & (~0xFF);
    return !!x;
}

int main(){
    printf("%d\n", int_shifts_are_ariththmetic());
}