#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isSorted(struct Node *head) {
    if (head == NULL || head->next == NULL)
        return 1;  // empty or single node = sorted

    while (head->next != NULL) {
        if (head->data > head->next->data)
            return 0;  // not sorted
        head = head->next;
    }
    return 1;
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

    if (isSorted(head))
        printf("The linked list is sorted in ascending order.\n");
    else
        printf("The linked list is NOT sorted.\n");

    return 0;
}
