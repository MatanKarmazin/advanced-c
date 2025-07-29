#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i, j;
} pair;

pair* arrayMatrixFriend(int** mat, int n, int* arrSize) {
    int i, j, k;
    pair* a;
    int count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] == 1) count++;
        }
    }
    a = (pair*)malloc(count * (sizeof(pair)));
    








    *arrSize = count;
    if (count > 0)
        return a;
    else
        return NULL;
}
