#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>


void freeMatrix(void** B, int size) {
    for (int i = 0; i < size; i++) {
        free(B[i]);
    }
    free(B);
}