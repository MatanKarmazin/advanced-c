#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int *fun(int a[], int n, int b[], int m, int *size) {
    int *c = (int *)malloc((n * m) * sizeof(int));
    assert(c);
    int i, j, k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                break;
            }
        }
        if (j == m) {
            c[k++] = a[i];
        }
    }
    int *newC = (int *)realloc(c, sizeof(int) * k);
    *size = k;
    return newC;
}