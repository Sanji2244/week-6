/*
 * 5. Write a program to search for a particular value in a linked list.
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
 * 5. Function to search for a particular value
 */
void searchElement(struct Node* head, int valueToFind) {
    struct Node* temp = head;
    int position = 1;
    
    // Traverse the list
    while (temp != NULL) {
        // Check if the current node's data matches the value
        if (temp->data == valueToFind) {
            printf("Found! Value %d is at position %d.\n", valueToFind, position);
            return; // Exit the function as soon as the value is found
        }
        temp = temp->next; // Move to the next node
        position++;        // Increment the position counter
    }
    
    // If the loop finishes, the value was not found
    printf("Not found. Value %d is not in the list.\n", valueToFind);
}

// Main function to demonstrate searching
int main() {
    struct Node* head = NULL;

    // Build a list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("The list is:\n");
    displayList(head);
    printf("\n");

    // Test 1: Search for a value that exists
    printf("Searching for 30...\n");
    searchElement(head, 30); // Output: Found! Value 30 is at position 3.
    
    // Test 2: Search for a value at the beginning
    printf("Searching for 10...\n");
    searchElement(head, 10); // Output: Found! Value 10 is at position 1.
    
    // Test 3: Search for a value that does not exist
    printf("Searching for 99...\n");
    searchElement(head, 99); // Output: Not found. Value 99 is not in the list.

    return 0;
}
