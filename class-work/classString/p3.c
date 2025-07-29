#include <ctype.h>
#include <stdio.h>
#include <string.h>

void reduceStr(char* str) {
    int i, j = 0;
    int len = strlen(str) - 1;
    for (i = 0; i < len - 1; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    char str[] = "i     live in     Israel";
    reduceStr(str);
    printf("%s\n", str);
}