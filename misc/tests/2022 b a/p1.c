#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* duplicateString(char* base, char* middle, int times) {
    char *str = (char*)calloc(times * strlen(base) + (times - 1) * strlen(middle) + 1), sizeof(char);
    int i;
    for (i = 0; i < times - 1; i++) {
        strcat(str, base);
        strcat(str, middle);
    }
    strcat(str, base);
    return str;
}