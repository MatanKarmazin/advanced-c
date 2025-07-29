#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct triad {
    int i, j, value;
} Triad;

typedef struct item {
    Triad data;
    struct item *next;
} Item;

typedef struct Node {
    Triad data;
    struct Node* next;
} Node;

Triad createThree(int i, int j, int value) {
    Triad newTriad;
    newTriad.i = i;
    newTriad.j = j;
    newTriad.value = value;
    return newTriad;
}

Node* insert(Node* head, Triad newTriad) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode);
    newNode->data = newTriad;
    newNode->next = head;
    return newNode;
}

void printList(Node* lst) {
    printf("List: ");
    while (lst != NULL) {
        printf("(%d, %d, %d) ", lst->data.i, lst->data.j, lst->data.value);
        lst = lst->next;
    }
    printf("\n");
}


void freeList(Node* lst) {
    Node* current = lst;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
