#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int data;
    struct item* next;
}Item;

Item* fun(Item* L1, Item* L2) {
    Item* common;
    int flag = L1->data;

    while (L1->data != L2->data) {
        L1 = L1->next;

        if (L1->data == flag) {
            L2 = L2->next;
        }
    }

    common = L1;
    
    while (L1->next->data != common->data) {
        L1 = L1->next;
    }
    
    flag = L2->data;
    L2 = L2->next;
    while (L2->data != flag) {
        L1->next->data = L2->data;
        L2 = L2->next;
        L1 = L1->next;
    }

    return common;
}
// Function to create a new item
Item* createItem(int data) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    newItem->data = data;
    newItem->next = newItem; // Initialize it to point to itself to form a circular list
    return newItem;
}

// Function to insert an item into the circular list
Item* insertItem(Item* head, int data) {
    Item* newItem = createItem(data);
    if (!head) {
        return newItem;
    }
    Item* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newItem;
    newItem->next = head;
    return head;
}

// Function to print the circular linked list
void printCircularList(Item* head) {
    if (!head) return;
    Item* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

int main() {
    // Creating first circular linked list
    Item* circle1 = NULL;
    circle1 = insertItem(circle1, 6);
    circle1 = insertItem(circle1, 5);
    circle1 = insertItem(circle1, 8);
    circle1 = insertItem(circle1, 2);

    // Creating second circular linked list
    Item* circle2 = NULL;
    circle2 = insertItem(circle2, 3);
    circle2 = insertItem(circle2, 5);
    circle2 = insertItem(circle2, 9);
    circle2 = insertItem(circle2, 4);
    circle2 = insertItem(circle2, 7);

    printf("Circle 1: ");
    printCircularList(circle1);

    printf("Circle 2: ");
    printCircularList(circle2);

    // Unite the two circular lists
    Item* common = fun(circle1, circle2);

    // Print the united circular list
    printf("United Circle: ");
    printCircularList(common);

    // Free allocated memory (note: actual implementation should free all nodes)
    free(circle1);
    free(circle2);

    return 0;
}
