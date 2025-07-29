#include <ctype.h>
#include <stdio.h>
#include <string.h>

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int reverseString(char* str) {
    char* end;
    int pal = 1;
    for (end = str + strlen(str) - 1; str < end; str++, end--) {
        if (*str != *end) {
            swap(str,end);
            pal = 0;
        }
    }
    return pal;
}

int main() {
    char* str = "adv";
    int result = reverseString(str);
    printf("%s\n", str);
    result ? printf("is palindrome\n") : printf("isn't palindrome\n");
    return 0;
}