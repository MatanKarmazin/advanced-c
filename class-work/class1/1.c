#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int *even_odd(int arr[], int size, int **a_odd, int *evenSize, int *oddSize) {
    int *evenArr = (int *)malloc(size * sizeof(int));
    assert(evenArr);
    int *oddArr = (int *)malloc(size * sizeof(int));
    assert(oddArr);
    int i, j = 0, k = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[j++] = arr[i];
        } else {
            oddArr[k++] = arr[i];
        }
    }
    int *a = (int *)realloc(evenArr, j * sizeof(int));
    assert(a);
    int *b = (int *)realloc(oddArr, k * sizeof(int));
    assert(b);
    *evenSize = j;
    *oddSize = k;
    *a_odd = b;
    return a;
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *oddPtr;
    int evenSize, oddSize;
    int *evenPtr = even_odd(arr, SIZE, &oddPtr, &evenSize, &oddSize);
    int i;
    for (i = 0; i < oddSize; i++) {
        printf("%2d ", oddPtr[i]);
    }
    printf("\n");
    for (i = 0; i < evenSize; i++) {
        printf("%2d ", evenPtr[i]);
    }
    printf("\n");
    free(oddPtr);
    free(evenPtr);
    return 0;
}