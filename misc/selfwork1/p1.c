#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int isAbundant(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum > num;
}


int countAbundants(int a, int b, int **abundants) {
    int size = b - a + 1;
    char *isAbundantArr = (char *)malloc(size * sizeof(char));
    assert(isAbundantArr);

    for (int i = 0; i < size; i++) {
        isAbundantArr[i] = isAbundant(a + i);
    }

    int abundantCount = 0;
    for (int i = 0; i < size; i++) {
        if (isAbundantArr[i]) {
            abundantCount++;
        }
    }

    *abundants = (int *)malloc(abundantCount * sizeof(int));
    assert(abundants);

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (isAbundantArr[i]) {
            (*abundants)[j++] = a + i;
        }
    }

    free(isAbundantArr);
    return abundantCount;
}

int main() {
    int a = 10, b = 40;
    int *abundants;
    int count = countAbundants(a, b, &abundants);

    if (count == 0) {
        printf("No abundant numbers found in the range [%d, %d]\n", a, b);
    } else {
        printf("Abundant numbers in the range [%d, %d]:\n", a, b);
        for (int i = 0; i < count; i++) {
            printf("%d ", abundants[i]);
        }
        printf("\n");
        free(abundants);
    }

    return 0;
}
