/*
 * 2. Write a program to insert a new node at the:
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
// --- End of Helper Functions ---


/*
 * 2a. Function to insert a node at the beginning [cite: 6]
 */
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head; // Link new node to the old head
    head = newNode;      // Make the new node the new head
    return head;
}

/*
 * 2b. Function to insert a node at the end [cite: 7]
 */
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

/*
 * 2c. Function to insert at a specified position
 * (Position 1 is the beginning)
 */
struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position. Must be 1 or greater.\n");
        return head;
    }

    // If position is 1, use insertAtBeginning logic
    if (pos == 1) {
        return insertAtBeginning(head, value);
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    // Traverse to the node *before* the desired position
    // Loop (pos - 2) times
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position %d is out of bounds.\n", pos);
            return head; // Don't insert
        }
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", pos);
        return head;
    }

    // Link the new node
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}


// Main function to demonstrate all insertions
int main() {
    struct Node* head = NULL;

    // Build an initial list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printf("Initial list:\n");
    displayList(head); 
    printf("\n");

    // a. Insert at beginning
    printf("Inserting 5 at the beginning:\n");
    head = insertAtBeginning(head, 5);
    displayList(head); 
    printf("\n");

    // b. Insert at end
    printf("Inserting 40 at the end:\n");
    head = insertAtEnd(head, 40);
    displayList(head); 
    printf("\n");

    // c. Insert at specified position
    printf("Inserting 99 at position 3:\n");
    head = insertAtPosition(head, 99, 3);
    displayList(head); 
    
    printf("Inserting 77 at position 1:\n");
    head = insertAtPosition(head, 77, 1);
    displayList(head);
    return 0;
}
