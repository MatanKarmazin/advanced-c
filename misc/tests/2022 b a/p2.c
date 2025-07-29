#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void List_num_add(node* L, int n) {
    node* head = NULL;
    node* tempList = L;
    int m = 0, count1 = 0, count2 = 0;
    int i;
    while (tempList != NULL) {
        count1++;
        tempList = tempList->next;
    }

    tempList = L;

    for (i = count1; i > 0; i--) {
        m += tempList->data;
        tempList = tempList->next;
    }

    tempList = L;
    m += n;
    int tempNum = m;

    while(tempNum){
        tempNum /= 10;
        count2++;
    }

    if (count1 == count2) {
        
    }
}