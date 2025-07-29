#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h> // for INT_MIN

/* Constant definitions */

#define N 3
#define ROWS 4
#define COLS 5

/* Type definitions */

typedef struct number {
    unsigned long long num;
    int sum;
} Number;

typedef struct triad {
    int i, j, value;
} Triad;

typedef struct item {
    Triad data;
    struct item* next;
} Item;

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int** matrixMaxNeighbor(int A[][COLS], int rows, int cols);
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2);

/* Declarations of auxiliary functions */

int isPrime(int num);
int digitSum(unsigned long long num);

int neighborMax(int A[][COLS], int rows, int cols, int i, int j);
int** allocMatrix(int rows, int cols);

Triad createThree(int i, int j, int value);
Item* insert(Item* head, Triad newTriad);

void printArray(Number* arr, int size);
void inputMatrix(int A[][COLS], int rows, int cols);
void printMatrix(int A[][COLS], int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);
void freeMatrix(void** A, int rows);
void inputDynamicMatrix(int** A, int rows, int cols);
void printList(Item* lst);
void freeList(Item* lst);

/* ------------------------------- */

int main() {
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf_s("%d", &all_Ex_in_loop) == 1) do {
            for (i = 1; i <= N; i++) printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-%d : ", N);
                scanf_s("%d", &select);
            } while ((select < 0) || (select > N));
            switch (select) {
                case 1:
                    Ex1();
                    break;
                case 2:
                    Ex2();
                    break;
                case 3:
                    Ex3();
                    break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}

/* Function definitions */

void Ex1() {
    int size;
    unsigned long long n1, n2;
    printf("Enter two numbers: ");
    scanf_s("%llu %llu", &n1, &n2);
    Number* result = primeSums(n1, n2, &size);
    printArray(result, size);
    printf("Size: %d\n\n", size);
    free(result);
}

void Ex2() {
    // Initialize the input matrix A
    int A[ROWS][COLS];
    inputMatrix(A, ROWS, COLS);
    printf("Input Matrix:\n");
    printMatrix(A, ROWS, COLS);
    printf("\n");
    // Calculate the matrix of maximum neighbors
    int** B = matrixMaxNeighbor(A, ROWS, COLS);
    // Print the matrix of maximum neighbors
    printf("Max neighbor Matrix:\n");
    printDynamicMatrix(B, ROWS, COLS);
    printf("\n");
    // Free dynamically allocated memory for B
    freeMatrix((void**)B, ROWS);
}

void Ex3() {
    int rows, cols;

    // Input static matrix dimensions
    printf("Enter number of rows: ");
    scanf_s("%d", &rows);
    printf("Enter number of columns: ");
    scanf_s("%d", &cols);

    // Allocate memory for the matrix
    int** A = allocMatrix(rows, cols);

    // Input values for the matrix
    inputDynamicMatrix(A, rows, cols);

    printf("Input Matrix:\n");
    printDynamicMatrix(A, rows, cols);

    // Initialize pointers to linked lists
    Item* pL1 = NULL;
    Item* pL2 = NULL;

    // Create linked lists based on matrix values
    createThreeLists(A, rows, cols, &pL1, &pL2);

    // Print the created lists
    printf("List 1: ");
    printList(pL1);
    printf("List 2: ");
    printList(pL2);
    printf("\n");

    // Free memory allocated for lists and matrix
    freeList(pL1);
    freeList(pL2);
    freeMatrix((void**)A, rows);
}

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size) {
    // Check for valid range
    if (n1 >= n2) {
        *p_size = 0;
        return NULL;
    }
    *p_size = 2;  // Default size to work with
    Number* arr = (Number*)malloc(*p_size * sizeof(Number));
    assert(arr);
    unsigned long long i;
    int sum, count = 0;
    // Iterate through the range [n1, n2]
    for (i = n1; i <= n2; i++) {
        if (count == *p_size) {
            *p_size *= 2;
            Number* temp = (Number*)realloc(arr, *p_size * sizeof(Number));
            if (temp == NULL) {
                free(arr);
                *p_size = 0;
                return NULL;
            }
            arr = temp;
        }
        sum = digitSum(i);
        // Check if the sum is prime
        if (isPrime(sum)) {
            arr[count].num = i;
            arr[count].sum = sum;
            count++;
        }
    }
    // If no valid numbers are found, free the memory and return NULL
    if (count == 0) {
        free(arr);
        arr = NULL;
    }
    // Update the size of the array and return it
    *p_size = count;
    return arr;
}

int** matrixMaxNeighbor(int A[][COLS], int rows, int cols) {
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

void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == i + j) {
                // Insert the current triad into the first list
                *pL1 = insert(*pL1, createThree(i, j, A[i][j]));
            }
            if (A[i][j] - j == j - i) {
                // Insert the current triad into the second list
                *pL2 = insert(*pL2, createThree(i, j, A[i][j]));
            }
        }
    }
}

/* Definitions of auxiliary functions */

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int digitSum(unsigned long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void printArray(Number* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Number: %llu, Digit Sum: %d\n", arr[i].num, arr[i].sum);
    }
}

void inputMatrix(int A[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for A[%d][%d]: ", i, j);
            scanf_s("%d", &A[i][j]);
        }
    }
}

void freeMatrix(void** B, int size) {
    for (int i = 0; i < size; i++) {
        free(B[i]);
    }
    free(B);
}

void printDynamicMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}

void printMatrix(int A[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}

int neighborMax(int A[][COLS], int rows, int cols, int i, int j) {
    int max = INT_MIN;
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

int** allocMatrix(int rows, int cols) {
    int** B = (int**)calloc(rows, sizeof(int**));
    assert(B);  // Ensure memory allocation was successful
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)calloc(cols, sizeof(int*));
        assert(B[i]);  // Ensure memory allocation was successful
    }
    return B;
}

Triad createThree(int i, int j, int value) {
    Triad newTriad;
    newTriad.i = i;
    newTriad.j = j;
    newTriad.value = value;
    return newTriad;
}

Item* insert(Item* head, Triad newTriad) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    assert(newNode);
    newNode->data = newTriad;
    newNode->next = head;
    return newNode;
}

void inputDynamicMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for A[%d][%d]: ", i, j);
            scanf_s("%d", &A[i][j]);
        }
    }
}

void printList(Item* lst) {
    printf("List: ");
    while (lst != NULL) {
        printf("(%d, %d, %d) ", lst->data.i, lst->data.j, lst->data.value);
        lst = lst->next;
    }
    printf("\n");
}

void freeList(Item* lst) {
    Item* current = lst;
    Item* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

/* ------------------- */
