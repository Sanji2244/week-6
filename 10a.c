#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* reverseIterative(struct Node *head) {
    struct Node *prev = NULL, *current = head, *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    return head;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int choice = 1;

    while (choice) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        printf("Continue? (1/0): ");
        scanf("%d", &choice);
    }

    printf("Original list:\n");
    display(head);

    head = reverseIterative(head);

    printf("Reversed list (Iterative):\n");
    display(head);

    return 0;
}
