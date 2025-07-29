#include <stdio.h>
#define N 10
#include <stdlib.h>

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int removeDup(int arr[], int size, int *newSize) {
    int i, j = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    *newSize = j;
    return
}

int main() {
    int arr[N] = {50, 60, 60, 72, 81, 81, 81, 81, 93, 93};
    int newSize;
    int arr1 = removeDup(arr, N, &newSize);

    printArray(arr1, newSize);
    return 0;
}