#include <stdio.h>
#include <string.h>

void decode(char* text) {
    int i, j;
    for (i = 0, j = 1; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            text[i] -= j++;
        } else {
            j = 1;
        }
    }
}


int main() {
    char str[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
    printf("string before decode:\n%s\n", str);
    decode(str);
    printf("string after decode:\n%s\n", str);
    // puts(str);
}