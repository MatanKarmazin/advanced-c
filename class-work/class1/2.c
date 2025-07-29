#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void biggie_smalls(char str[], int len, char **bigArr, char **smallArr,
                   int *bigSize, int *smallSize) {
    int i, b = 0, s = 0;
    for (i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            b++;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            s++;
        }
    }
    char *bigCaps = (char *)malloc(b);
    assert(bigCaps);
    char *smallCaps = (char *)malloc(s);
    assert(smallCaps);
    *bigSize = b;
    *smallSize = s;
    b = 0;
    s = 0;
    for (i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            bigCaps[b++] = str[i];
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            smallCaps[s++] = str[i];
        }
    }
    *bigArr = bigCaps;
    *smallArr = smallCaps;
}

int main() {
    char str[] = {'a', 'b', 'd', 'S', 'T', 'E', 'Z', 'y', 'x', 'F'};
    int len = sizeof(str);
    char *bigArr, *smallArr;
    int bigSize, smallSize;
    biggie_smalls(str, len, &bigArr, &smallArr, &bigSize, &smallSize);
    int i;
    for (i = 0; i < len; i++) {
        printf("%c ", bigArr[i]);
    }
    printf("\n");
    for (i = 0; i < len; i++) {
        printf("%c ", smallArr[i]);
    }
    printf("\n");
    free(bigArr);
    free(smallArr);
    return 0;
}