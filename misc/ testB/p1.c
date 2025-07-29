#include <stdio.h>

typedef struct item {
    int digit;
    struct item* next;
} Item;

int numListCmp(Item* L1, Item* L2) {
    Item *temp1 = L1, *temp2 = L2;
    int count1 = 0, count2 = 0;
    while (temp1 != NULL) {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        count2++;
        temp2 = temp2->next;
    }
    if (count1 > count2) return 1;
    if (count1 < count2) return -1;
    temp1 = L1;
    temp2 = L2;
    while (temp1 != NULL) {
        if (temp1->digit > temp2->digit) return 1;
        if (temp1->digit < temp2->digit) return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0;
}

int main() {
    // Create first linked list: 1 -> 2 -> 3
    Item node3 = {3, NULL};
    Item node2 = {2, &node3};
    Item node1 = {1, &node2};

    // Create second linked list: 1 -> 2 -> 3
    Item node6 = {3, NULL};
    Item node5 = {2, &node6};
    Item node4 = {1, &node5};

    // Create third linked list: 1 -> 2 -> 4
    Item node9 = {4, NULL};
    Item node8 = {2, &node9};
    Item node7 = {1, &node8};

    // Compare first and second lists (should be equal)
    int result1 = numListCmp(&node1, &node4);
    printf("Comparison result between list 1 and list 2: %d\n", result1);  // Expected output: 0

    // Compare first and third lists (first list is smaller)
    int result2 = numListCmp(&node1, &node7);
    printf("Comparison result between list 1 and list 3: %d\n", result2);  // Expected output: -1

    // Create fourth linked list: 1 -> 2
    Item node11 = {2, NULL};
    Item node10 = {1, &node11};

    // Compare first and fourth lists (first list is longer)
    int result3 = numListCmp(&node1, &node10);
    printf("Comparison result between list 1 and list 4: %d\n", result3);  // Expected output: 1

    return 0;
}
