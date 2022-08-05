#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size) {
    if(!nmemb || !size || nmemb * size < nmemb || nmemb * size < size)
    // nmemb * size / size != nmemb
        return NULL;
    void* ptr = malloc(nmemb* size);
    if(!ptr)
        return NULL;
    return memset(ptr, 0, nmemb * size / sizeof(int));
}

int main(int argc, char const *argv[])
{
    assert(calloc(10, sizeof(int)));
    assert(!calloc(0xFFFFFFFF, sizeof(int)));
    return 0;
}
