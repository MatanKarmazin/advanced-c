#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define N 5

int** allocMatrix(int rows, int cols) {
    int** B = (int**)calloc(rows, sizeof(int**));
    assert(B);
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)calloc(cols, sizeof(int*));
        assert(B[i]);
    }
    return B;
}

void inputDynamicMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++) {
            printf("Enter value for A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
}

void printDynamicMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // int rows, cols;
    // printf("enter rows and cols: ");
    // scanf("%d %d", &rows, &cols);
    int** A = allocMatrix(N, N);
    inputDynamicMatrix(A, N, N);
    printDynamicMatrix(A, N, N);
    return 0;
}