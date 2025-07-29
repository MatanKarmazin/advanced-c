#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


// Function prototypes
int neighborMax(int A[][cols], int rows, int cols, int i, int j);
int** allocMatrix(int rows, int cols);
int** matrixMaxNeighbor(int A[][cols], int rows, int cols);
void printMatrix(int A[][cols], int rows, int cols);
void freeMatrix(void** B, int n);
void inputMatrix(int A[][cols], int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);



void main() {
    int rows, cols;
    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    // Initialize the input matrix A
    int A[rows][cols];
    inputMatrix(A, rows, cols);
    printf("Input Matrix:\n");
    printMatrix(A, rows, cols);
    // Calculate the matrix of maximum neighbors
    int** B = matrixMaxNeighbor(A, rows, cols);
    // Print the matrix of maximum neighbors
    printDynamicMatrix(B, rows, cols);
    // Free dynamically allocated memory for B
    freeMatrix((void**)B, rows);
}

// Function to input values into a matrix
void inputMatrix(int A[][cols], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

// Function to free dynamically allocated memory for a matrix
void freeMatrix(void** B, int size) {
    // Free dynamically allocated memory for each row
    for (int i = 0; i < size; i++) {
        free(B[i]);
    }
    // Free the memory allocated for the array of pointers
    free(B);
}

// Function to print a dynamic matrix
void printDynamicMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}

// Function to print a matrix
void printMatrix(int A[][cols], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the maximum neighbor of an element in a matrix
int neighborMax(int A[][cols], int rows, int cols, int i, int j) {
    int max = 0;
    // Check top neighbor
    if (i > 0 && A[i - 1][j] > max) {
        max = A[i - 1][j];
    }
    // Check bottom neighbor
    if (i < rows - 1 && A[i + 1][j] > max) {
        max = A[i + 1][j];
    }
    // Check left neighbor
    if (j > 0 && A[i][j - 1] > max) {
        max = A[i][j - 1];
    }
    // Check right neighbor
    if (j < cols - 1 && A[i][j + 1] > max) {
        max = A[i][j + 1];
    }
    return max;
}

// Function to allocate memory for a matrix
int** allocMatrix(int rows, int cols) {
    int** B = (int**)malloc(rows * sizeof(int*));
    assert(B);  // Ensure memory allocation was successful
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)malloc(cols * sizeof(int));
    }
    return B;
}

// Function to calculate the matrix of maximum neighbors
int** matrixMaxNeighbor(int A[][cols], int rows, int cols) {
    // Allocate memory for the matrix of maximum neighbors
    int** B = allocMatrix(rows, cols);
    // Calculate the maximum neighbor for each element in A and store it in B
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[i][j] = neighborMax(A, rows, cols, i, j);
        }
    }
    return B;
}
