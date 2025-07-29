#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define COLS 3
#define ROWS 3

// Function to print a static matrix
void printMatrixStatic(int A[][COLS], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a dynamic matrix
void printMatrixDynamic(int **A, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to input values into a dynamic matrix
void inputMatrix(int **A, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Enter value for B[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

// Function to free a dynamic matrix
void freeMatrix(int **A, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(A[i]);
    }
    free(A);
}

// Function to allocate memory for a dynamic matrix
int **allocMatrix(int rows, int cols) {
    int i;
    int **A = (int **)malloc(rows * sizeof(int *));
    assert(A); // Ensure memory allocation was successful
    for (i = 0; i < rows; i++) {
        A[i] = (int *)malloc(cols * sizeof(int));
        assert(A[i]); // Ensure memory allocation was successful
    }
    return A;
}

int main() {
    // Define and print a static matrix
    int A[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("Matrix A: \n");
    printMatrixStatic(A, ROWS);

    // Allocate memory for a dynamic matrix
    int **B = allocMatrix(ROWS, COLS);

    // Input values into the dynamic matrix
    inputMatrix(B, ROWS);

    // Print the dynamic matrix
    printf("Matrix B: \n");
    printMatrixDynamic(B, ROWS);

    // Free the allocated memory
    freeMatrix(B, ROWS);

    return 0;
}
