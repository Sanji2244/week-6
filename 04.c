/*
 * 4. Write a program to count the total number of nodes in a linked list.
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

// Helper to build a list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Helper to display the list
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
 * 4. Function to count the total number of nodes
 */
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    // Traverse the list and increment count for each node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// Main function to demonstrate counting
int main() {
    struct Node* head = NULL;

    // Build a list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("The list is:\n");
    displayList(head);
    
    // Count the nodes
    int totalNodes = countNodes(head);
    printf("\nTotal number of nodes: %d\n", totalNodes); // Output: 4

    // Count an empty list
    struct Node* emptyHead = NULL;
    printf("\nTotal number of nodes in an empty list: %d\n", countNodes(emptyHead)); // Output: 0

    return 0;
}
