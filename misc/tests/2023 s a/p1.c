#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorItem {
    int data;
    struct vectorItem* next;
} VectorItem;

VectorItem* createVector() {
    VectorItem *head = NULL, *tail = NULL, *newItem;
    int i, size, data;
    printf("Enter the number of elements in the vector: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        printf("enter data for the %d item: ", i + 1);
        scanf("%d", &data);
        newItem = (VectorItem*)malloc(sizeof(VectorItem));
        newItem->data = data;
        if (head == NULL)
            head = tail = newItem;
        else {
            tail->next = newItem;
            tail = newItem;
        }
    }
    return head;
}

VectorItem* multipleVector(VectorItem* a, VectorItem* b) {
    int aValue, bValue;
    VectorItem *head = NULL, *newItem;
    head = newItem = (VectorItem*)calloc(1, sizeof(VectorItem));
    do {
        aValue = (a) ? a->data : 0;
        bValue = (b) ? b->data : 0;
        newItem->data = aValue * bValue;
        if (a) a = a->next;
        if (b) b = b->next;
        if (a || b) {
            newItem->next = (VectorItem*)calloc(1, sizeof(VectorItem));
            newItem = newItem->next;
        }
    } while (a || b);
    return head;
}

void printList(VectorItem* head) {
    VectorItem* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    VectorItem* vectorA = NULL;
    VectorItem* vectorB = NULL;

    printf("Create vector A:\n");
    vectorA = createVector();
    printf("Create vector B:\n");
    vectorB = createVector();

    VectorItem* result = multipleVector(vectorA, vectorB);
    printf("Result of element-wise multiplication:\n");
    printList(result);

    return 0;
}
