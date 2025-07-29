#include <ctype.h>
#include <stdio.h>
#include <string.h>

void Counter(char* str, int* smallCount, int* bigCount, int* numCount, int* otherCount) {
    // smallCount = 0, bigCount = 0, numCount = 0, otherCount = 0;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            smallCount++;
        } else if (*str >= 'A' && *str <= 'Z') {
            bigCount++;
        } else if (*str >= '0' && *str <= '9') {
            numCount++;
        } else {
            otherCount++;
        }
        str++;
    }
}

int main() {
    int smallCount, bigCount, numCount, otherCount;
    smallCount = bigCount = numCount = otherCount = 0;
    char str[] = "123cghGGH[]";
    Counter(str, &smallCount, &bigCount, &numCount, &otherCount);
    printf("%d %d %d %d\n", smallCount, bigCount, numCount, otherCount);
    return 0;
}