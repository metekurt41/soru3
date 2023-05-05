
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* merge(struct node* l1, struct node* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct node* head1 = (struct node*)malloc(sizeof(struct node));
    struct node* second1 = (struct node*)malloc(sizeof(struct node));
    struct node* third1 = (struct node*)malloc(sizeof(struct node));

    head1->data = 1;
    head1->next = second1;

    second1->data = 3;
    second1->next = third1;

    third1->data = 5;
    third1->next = NULL;

    struct node* head2 = (struct node*)malloc(sizeof(struct node));
    struct node* second2 = (struct node*)malloc(sizeof(struct node));
    struct node* third2 = (struct node*)malloc(sizeof(struct node));

    head2->data = 2;
    head2->next = second2;

    second2->data = 4;
    second2->next = third2;

    third2->data = 6;
    third2->next = NULL;

    struct node* mergedList = merge(head1, head2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}