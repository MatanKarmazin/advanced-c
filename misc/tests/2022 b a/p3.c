#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int data;
    struct item* next;
} Item;

Item* create_node(int data) {
    Item* new_node = (Item*)malloc(sizeof(Item));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Item* head) {
    Item* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

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
    L1->next = common;

    return common;
}

int main() {
    // יצירת רשימה מקושרת L1
    Item* L1 = create_node(1);
    L1->next = create_node(2);
    L1->next->next = create_node(3);
    L1->next->next->next = create_node(4);
    L1->next->next->next->next = create_node(5);
    L1->next->next->next->next->next = L1->next;  // יצירת לולאה ברשימה

    // יצירת רשימה מקושרת L2
    Item* L2 = create_node(6);
    L2->next = create_node(7);
    L2->next->next = create_node(8);
    L2->next->next->next = L1->next->next;  // יצירת צומת משותפת עם L1

    // הדפסת הרשימות
    printf("List L1: ");
    print_list(L1);
    printf("List L2: ");
    print_list(L2);

    // קריאה לפונקציה
    Item* common_node = fun(L1, L2);

    // הדפסת התוצאה
    if (common_node != NULL) {
        printf("Common node found with data: %d\n", common_node->data);
    } else {
        printf("No common node found\n");
    }

    // שחרור זיכרון (הערה: במקרה זה יש לולאות אז קשה לשחרר הכל בצורה פשוטה)
    // free_list(L1);
    // free_list(L2);

    return 0;
}
