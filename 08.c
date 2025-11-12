#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void multiplyByTen(struct Node *head) {
    while (head != NULL) {
        head->data = head->data * 10;
        head = head->next;
    }
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

    multiplyByTen(head);

    printf("List after multiplying each element by 10:\n");
    display(head);

    return 0;
}
