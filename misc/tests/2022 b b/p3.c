#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char model[20];
    int price;
    int year;
} car;

typedef struct item {
    int price;
    int year;
    struct item* next;
} Item;

Item* appropriateCar(char* fileName, char* desired_model, int max_price, int min_year) {
    FILE* fp = fopen(fileName, "rb");
    car unit;
    Item *lst, *curr;
    if (!fp) return NULL;
    curr = lst = (Item*)malloc(sizeof(Item));

    fread(&unit, sizeof(car), 1, fp);
    while (!feof(fp)) {
        if (strcmp(unit.model, desired_model) == 0 && unit.price <= max_price &&
            unit.year >= min_year) {
            curr->next = (Item*)malloc(sizeof(Item));
            curr = curr->next;
            curr->price = unit.price;
            curr->year = unit.year;
        }
        fread(&unit, sizeof(car), 1, fp);
    }
    curr->next = NULL;
    /* Deleting dummy */
    curr = lst;
    lst = lst->next;
    free(curr);
    fclose(fp);
    return lst;
}