#include <stdio.h>
#include <stdlib.h>
#define COLS 5

void kaki(int A[][COLS], int rows, int cols, char* fileName) {
    FILE* fp = fopen(fileName, "r");
    int temp;
    if (!fp) return;
    while (fp != EOF) {
        fsacnf(fp, "%d", &temp);
        while
    }
}