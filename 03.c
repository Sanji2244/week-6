/*
 * 3. Write a program to delete a node from:
 * - Beginning
 * - End
 * - Specified position
 */
#include <stdio.h>
#include <stdlib.h>

// --- Basic Node Structure and Helper Functions (from Q1) ---
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

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List: HEAD -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Helper to build a list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}
// --- End of Helper Functions ---


/*
 * 3a. Function to delete a node from the beginning [cite: 11]
 */
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    
    struct Node* temp = head; // Store the node to be deleted
    head = head->next;      // Move head to the next node
    
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp); // Free the old head
    
    return head;
}

/*
 * 3b. Function to delete a node from the end [cite: 13]
 */
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    // If there is only one node
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        return NULL; // The list is now empty
    }

    // Traverse to the *second to last* node
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Now 'temp' is the second to last node
    struct Node* nodeToDelete = temp->next; // This is the last node
    printf("Deleted %d from end.\n", nodeToDelete->data);
    
    temp->next = NULL; // Unlink the last node
    free(nodeToDelete); // Free it
    
    return head;
}

/*
 * 3c. Function to delete from a specified position [cite: 14]
 * (Position 1 is the beginning)
 */
struct Node* deleteFromPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (pos < 1) {
        printf("Invalid position.\n");
        return head;
    }

    // If position is 1, use deleteFromBeginning logic
    if (pos == 1) {
        return deleteFromBeginning(head);
    }

    // Traverse to the node *before* the one to be deleted
    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position %d is out of bounds.\n", pos);
            return head;
        }
        temp = temp->next;
    }

    // Check if target node (temp->next) exists
    if (temp->next == NULL) {
        printf("Position %d is out of bounds.\n", pos);
        return head;
    }

    // 'temp' is at node (pos - 1)
    struct Node* nodeToDelete = temp->next; // This is the node at 'pos'
    
    // Bypass the node
    temp->next = nodeToDelete->next; // or temp->next = temp->next->next;
    
    printf("Deleted %d from position %d.\n", nodeToDelete->data, pos);
    free(nodeToDelete);
    
    return head;
}

// Main function to demonstrate all deletions
int main() {
    struct Node* head = NULL;

    // Build an initial list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    printf("Initial list:\n");
    displayList(head); // List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    printf("\n");

    // a. Delete from beginning [cite: 11]
    printf("Deleting from beginning:\n");
    head = deleteFromBeginning(head);
    displayList(head); // List: 20 -> 30 -> 40 -> 50 -> NULL
    printf("\n");

    // b. Delete from end [cite: 13]
    printf("Deleting from end:\n");
    head = deleteFromEnd(head);
    displayList(head); // List: 20 -> 30 -> 40 -> NULL
    printf("\n");

    // c. Delete from specified position [cite: 14]
    printf("Deleting from position 2:\n");
    head = deleteFromPosition(head, 2);
    displayList(head); // List: 20 -> 40 -> NULL
    
    return 0;
}
