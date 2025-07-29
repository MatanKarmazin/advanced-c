#include <stdio.h>
#include <string.h>

int mystery(int x, int *y, int *z);
int d;
int main() {
    int a = 0, b = 0, c = 0;
    char *w = "ABCDEFGHIJKLMNOPQ";
    char *st = NULL, *pt = NULL;
    mystery(a, &b, &c);
    printf("%d %d %d %d\n", a, b, c, d);
    mystery(c, &d, &a);
    printf("%d %d %d %d\n", a, b, c, d);
    a = mystery(a, &a, &c);
    printf("%d %d %d %d\n", a, b, c, d);
    st = w;
    pt = st + strlen(w) / 2;
    while (pt > st) {
        printf("%c", *pt);
        pt -= 2;
    }
    printf("\n");
    return 0;
}
int mystery(int x, int *y, int *z) {
    x++;
    (*y)++;
    --*z;
    ++d;
    return x;
}