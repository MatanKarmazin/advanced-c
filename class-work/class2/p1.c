 #include <assert.h>
 #include <stdlib.h>
 #include <stdio.h>

 void * realloc1(void *memblock, unsigned size_old, unsigned size_new) {
    void *old = (void*)malloc(size_old);
    assert(old);
    void *new = (void*)malloc(size_new);
    assert(new);
    free(old);
    return &new;
 }

 int main() {





    return 0;
 }