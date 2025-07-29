#include <stdio.h>
#define COLS 4
#define ROWS 4

int neighborMax(int A[][COLS], int rows, int cols, int i, int j) {
    int max = 0;

    // Check top neighbor
    if (i > 0) {
        if (A[i - 1][j] > max) {
            max = A[i - 1][j];
        }
    }

    // Check bottom neighbor
    if (i < rows - 1) {
        if (A[i + 1][j] > max) {
            max = A[i + 1][j];
        }
    }

    // Check left neighbor
    if (j > 0) {
        if (A[i][j - 1] > max) {
            max = A[i][j - 1];
        }
    }

    // Check right neighbor
    if (j < cols - 1) {
        if (A[i][j + 1] > max) {
            max = A[i][j + 1];
        }
    }

    return max;
}

void inputMatrix(int A[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}


int main() {
    int A[ROWS][COLS] = {5, 12, 6, 8, 4, 7, 1, 9, 13, 20, 5, 2, 18, 10, 2, 6};
    printf("max: %d\n", neighborMax(A, ROWS, COLS, 1, 1));
    return 0;
}