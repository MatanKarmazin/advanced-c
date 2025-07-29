#include <ctype.h>
#include <stdio.h>
#include <string.h>

int nums_in_halves(char* str, int* num1, int* num2) {
    *num1 = 0;
    *num2 = 0;
    int i;
    int len = strlen(str);
    if (len % 2 == 0) {
        for (i = 0; i < (len / 2) - 1; i++) {
            if (islower(str[i])) num1++;
        }
        for (i = (len / 2); i < len - 1; i++) {
            if (isupper(str[i])) num2++;
        }
        return 0;
    }

    else {
        for (i = 0; i < (len / 2) - 1; i++) {
            if (islower(str[i])) num1++;
        }
        for (i = (len / 2) + 1; i < len; i++) {
            if (isupper(str[i])) num2++;
        }
    }
    if (isdigit(*str / 2))
        return 1;
    else
        return -1;
}
