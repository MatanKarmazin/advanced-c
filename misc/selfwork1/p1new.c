#include <stdio.h>
#include <stdlib.h>

int isAbundant(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum > n;
}

int findAbundantNumbers(int a, int b, int *abundants) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (isAbundant(i)) {
            abundants[count++] = i;
        }
    }
    return count;
}

int main() {
    int a, b;
    printf("Enter the range (a, b): ");
    scanf("%d %d", &a, &b);

    int *abundants = (int *)malloc((b - a + 1) * sizeof(int));
    if (abundants == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    int count = findAbundantNumbers(a, b, abundants);

    if (count == 0) {
        printf("There are no abundant numbers in the range (%d, %d).\n", a, b);
    } else {
        printf("The abundant numbers in the range (%d, %d) are:\n", a, b);
        for (int i = 0; i < count; i++) {
            printf("%d ", abundants[i]);
        }
        printf("\n");
    }

    free(abundants);

    return 0;
}
