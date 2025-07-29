#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int data;
    struct item* next;
} Item;

Item* bolbol(Item** A, int size, Item* L) {
    int i, j, counter = 0;
    Item* temp = L;
    while (temp != NULL) {
        temp = temp->next;
        counter++;
    }

    Item* newList = (Item*)malloc(sizeof(Item));
    Item* head = newList;

    temp = L;

    for (i = 0; i < size; i++) {
        for (j = 0; j < counter; j++) {
            if (temp->data == A[i]->data) {
                temp = temp->next;
                A[i] = A[i]->next;
            } else
                break;
        }
        head->data = i;
        head = head->next;
        temp = L;
    }

    if (newList == NULL) return NULL;
    return newList;
}

void printList(Item* head) {
    Item* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating the linked list L
    Item* L = (Item*)malloc(sizeof(Item));
    L->data = 8;
    L->next = (Item*)malloc(sizeof(Item));
    L->next->data = 2;
    L->next->next = (Item*)malloc(sizeof(Item));
    L->next->next->data = 5;
    L->next->next->next = NULL;

    // Creating the array of linked lists A
    int size = 5;
    Item** A = (Item**)malloc(size * sizeof(Item*));

    // A[0]
    A[0] = (Item*)malloc(sizeof(Item));
    A[0]->data = 8;
    A[0]->next = (Item*)malloc(sizeof(Item));
    A[0]->next->data = 2;
    A[0]->next->next = (Item*)malloc(sizeof(Item));
    A[0]->next->next->data = 5;
    A[0]->next->next->next = (Item*)malloc(sizeof(Item));
    A[0]->next->next->next->data = 1;
    A[0]->next->next->next->next = (Item*)malloc(sizeof(Item));
    A[0]->next->next->next->next->data = 6;
    A[0]->next->next->next->next->next = NULL;

    // A[1]
    A[1] = (Item*)malloc(sizeof(Item));
    A[1]->data = 8;
    A[1]->next = (Item*)malloc(sizeof(Item));
    A[1]->next->data = 2;
    A[1]->next->next = (Item*)malloc(sizeof(Item));
    A[1]->next->next->data = 5;
    A[1]->next->next->next = NULL;

    // A[2]
    A[2] = (Item*)malloc(sizeof(Item));
    A[2]->data = 8;
    A[2]->next = (Item*)malloc(sizeof(Item));
    A[2]->next->data = 2;
    A[2]->next->next = (Item*)malloc(sizeof(Item));
    A[2]->next->next->data = 5;
    A[2]->next->next->next = NULL;

    // A[3]
    A[3] = (Item*)malloc(sizeof(Item));
    A[3]->data = 1;
    A[3]->next = (Item*)malloc(sizeof(Item));
    A[3]->next->data = 8;
    A[3]->next->next = (Item*)malloc(sizeof(Item));
    A[3]->next->next->data = 2;
    A[3]->next->next->next = (Item*)malloc(sizeof(Item));
    A[3]->next->next->next->data = 5;
    A[3]->next->next->next->next = (Item*)malloc(sizeof(Item));
    A[3]->next->next->next->next->data = 3;
    A[3]->next->next->next->next->next = NULL;

    // A[4]
    A[4] = (Item*)malloc(sizeof(Item));
    A[4]->data = 8;
    A[4]->next = (Item*)malloc(sizeof(Item));
    A[4]->next->data = 2;
    A[4]->next->next = (Item*)malloc(sizeof(Item));
    A[4]->next->next->data = 5;
    A[4]->next->next->next = (Item*)malloc(sizeof(Item));
    A[4]->next->next->next->data = 9;
    A[4]->next->next->next->next = NULL;

    // Calling bolbol function
    Item* newList = bolbol(A, size, L);

    // Printing the result
    printList(newList);

    // Freeing allocated memory
    for (int i = 0; i < size; i++) {
        Item* current = A[i];
        while (current != NULL) {
            Item* next = current->next;
            free(current);
            current = next;
        }
    }
    free(A);

    Item* current = L;
    while (current != NULL) {
        Item* next = current->next;
        free(current);
        current = next;
    }

    current = newList;
    while (current != NULL) {
        Item* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}