#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

void good_echo() {
    char buf[8];
    char* res = fgets(buf, sizeof buf, stdin);
    if(!res || strlen(res) > sizeof buf - 1)
        return ;
    printf("%s\n", res);
}

void main(){
    good_echo();
}