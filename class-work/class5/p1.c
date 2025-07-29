#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(Node** head, char value) {
    Node* newNode = createNode(value);
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void buildSortedList(Node** head) {
    char ch;
    printf("Enter characters (without space key, press Enter to stop): ");
    while ((ch = getchar()) != '\n') {
        insertSorted(head, ch);
    }
}


int main() {
    Node* head = NULL;

    buildSortedList(&head);
    printList(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
