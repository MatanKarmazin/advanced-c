#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct monom {
    double coefficient;
    int power;
} Monom;

typedef struct item {
    Monom mon;
    struct item* next;
} Item;

Item* createPolynom(Item* L) {
    Item* curr = L, *P = NULL;
    int maxPower = 0, power;
    double *arr;

    while (curr) {
        if (curr->mon.power > maxPower) {
            maxPower = curr->mon.power;
        }
        curr = curr->next;
    }

    arr = (double*)calloc(maxPower + 1, sizeof(double));
    curr = L;
    while (curr) {
        arr[curr->mon.power] += curr->mon.coefficient;
        curr = curr->next;
    }
    curr = L;
    for (power = 0; power <= maxPower; power++) {
        if(arr[power] != 0) {
            curr = (Item*)malloc(sizeof(Item));
            curr->next = P;
            P = curr;
            P->mon.coefficient = arr[power];
            P->mon.power = power;
        }
    }

    free(arr);
    return P;
}