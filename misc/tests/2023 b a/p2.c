#include <stdio.h>
#include <stdlib.h>

int arrSorted(int *a, int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int columnSorted(int **ar, int m, int col) {
    int i;
    for (i = 1; i < m; i++) {
        if (ar[i][col] >= ar[i - 1][col]) {
            return 0;
        }
    }
    return 1;
}

void sortedRowsCols(int **ar, int m, int n, int **ar_s_rows, int *num_s_rows, int **ar_s_cols,
                    int *num_s_cols) {
    int i, j;
    *num_s_rows = *num_s_cols = 0;
    *ar_s_rows = (int *)calloc(m, sizeof(int));
    *ar_s_cols = (int *)calloc(n, sizeof(int));

    for (i = 0; i < m; i++) {
        if (arrSorted(a[i], n)) {
            (*ar_s_rows)[*num_s_rows++] = i;
        }
    }

    for (j = 0; j < n; i++) {
        if (columnSorted(ar, m, n)) {
            (*ar_s_cols)[*num_s_cols++] = i;
        }
    }
    
    *ar_s_rows = (int *)realloc(*ar_s_rows, *num_s_rows * sizeof(int));
    *ar_s_cols = (int *)realloc(*ar_s_cols, *num_s_cols * sizeof(int));
}