#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* Jose(node* lst, int m) {
    if (lst == NULL) return NULL;
    int i;
    node* curr = NULL;
    node* prev = NULL;
    node* temp;
    while (lst != NULL) {
        for (i = 0; i < m - 2; i++) {
            lst = lst->next;
        }
        temp = lst->next;
        lst->next = temp->next;
        temp->next = NULL;

        if (curr == NULL){
            curr = prev = temp;
        } else {
            prev->next = temp;
            prev = prev->next;
        }
        lst = lst->next;
    }
    return curr;
}