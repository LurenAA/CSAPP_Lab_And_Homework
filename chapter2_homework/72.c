#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void copy_int(int val, void* buf, int maxbytes) {
    int size_val = sizeof(val);
    if(maxbytes - size_val >= 0)
        memcpy(buf, (void *)&val, sizeof(val));
}

int main(int argc, char const *argv[])
{
    char* buf = malloc(10);
    copy_int(0x1111, buf, 10);
    printf("%x%x%x%x\n", buf[0], buf[1], buf[2], buf[3]);
    return 0;
}
