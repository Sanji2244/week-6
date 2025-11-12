/*
 * 6. Write a program that removes all nodes that have duplicate information.
 * (This solution assumes an unsorted list.)
 */
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List: HEAD -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


/*
 * 6. Function to remove duplicate nodes
 */
void removeDuplicates(struct Node* head) {
    if (head == NULL) return;

    struct Node* current = head;

    // Outer loop: Iterate through each node
    while (current != NULL) {
        struct Node* runner = current; 
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                struct Node* nodeToDelete = runner->next;
                runner->next = runner->next->next; 
                free(nodeToDelete); 
            } else {
                runner = runner->next;
            }
        }
        current = current->next; 
    }
}

// Main function to demonstrate duplicate removal
int main() {
    struct Node* head = NULL;

    // Build a list with duplicates
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 40);

    printf("Original list with duplicates:\n");
    displayList(head);
    // Remove duplicates
    removeDuplicates(head);
    
    printf("\nList after removing duplicates:\n");
    displayList(head);

    return 0;
}
