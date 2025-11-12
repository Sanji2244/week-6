#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int countOccurrences(struct Node *head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
}

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int choice = 1, key;

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

    printf("Enter the item to count: ");
    scanf("%d", &key);

    int count = countOccurrences(head, key);
    printf("The item %d occurs %d time(s) in the list.\n", key, count);

    return 0;
}
