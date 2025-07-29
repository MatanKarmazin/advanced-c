#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct triad {
    int i, j, value;
} Triad;

typedef struct item {
    Triad data;
    struct item* next;
} Item;

typedef struct Node {
    Triad data;
    struct Node* next;
} Node;

// Function declarations
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2);
Triad createThree(int i, int j, int value);
Node* insert(Node* head, Triad newTriad);
int** allocMatrix(int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);
void inputDynamicMatrix(int** A, int rows, int cols);
void printList(Node* lst);
void freeList(Node* lst);
void freeMatrix(void** B, int n);

// Main function
int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the matrix
    int** A = allocMatrix(rows, cols);

    // Input values for the matrix
    inputDynamicMatrix(A, rows, cols);

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

    // Free memory allocated for lists and matrix
    freeList(pL1);
    freeList(pL2);
    freeMatrix((void**)A, rows);
}
// Function to create two linked lists of triads based on matrix values
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

// Function to allocate memory for a matrix of integers
int** allocMatrix(int rows, int cols) {
    // Allocate memory for an array of row pointers
    int** B = (int**)malloc(rows * sizeof(int*));
    assert(B);  // Ensure memory allocation was successful
    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)malloc(cols * sizeof(int));
    }
    return B;
}

// Function to print a dynamic matrix
void printDynamicMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// Function to create a new triad with given values
Triad createThree(int i, int j, int value) {
    Triad newTriad;
    newTriad.i = i;
    newTriad.j = j;
    newTriad.value = value;
    return newTriad;
}

// Function to insert a new triad node at the beginning of a linked list
Node* insert(Node* head, Triad newTriad) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode);
    newNode->data = newTriad;
    newNode->next = head;
    return newNode;
}

// Function to input values for a dynamic matrix
void inputDynamicMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

// Function to print a linked list of triads
void printList(Node* lst) {
    printf("List: ");
    while (lst != NULL) {
        printf("(%d, %d, %d) ", lst->data.i, lst->data.j, lst->data.value);
        lst = lst->next;
    }
    printf("\n");
}

// Function to free memory allocated for a linked list of triads
void freeList(Node* lst) {
    Node* current = lst;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
// Function to free dynamically allocated memory for a matrix
void freeMatrix(void** B, int n) {
    // Free dynamically allocated memory for each row
    for (int i = 0; i < n; i++) {
        free(B[i]);
    }
    // Free the memory allocated for the array of pointers
    free(B);
}