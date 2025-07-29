#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* ptr;
} dyn_array;

dyn_array* divNumbers(int* A, int sz, int n) {
    dyn_array* B = (dyn_array*)calloc((n - 1), sizeof(dyn_array));
    int i, j, k = 0, count = 0;
    for (j = 2; j <= n; j++) {
        B[j - 2].ptr = (int*)calloc(sz, sizeof(int));
        for (i = 0; i < sz; i++) {
            if (A[i] % j == 0) {
                count++;
                B[j - 2].ptr[k++] = A[i];
            }
        }
        B[i - 2].ptr = (int*)realloc(B[i - 2].ptr, k * sizeof(int));

        B[i - 2].size = k;
    }
    return B;
}