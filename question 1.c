/*
 * 1. Write a program to create a singly linked list and display its elements.
 */
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1); // Exit if memory is full
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end (to help create the list)
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty, make the new node the head
    if (head == NULL) {
        return newNode;
    }

    // Otherwise, traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Link the last node to the new node
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: HEAD -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate creation and display
int main() {
    struct Node* head = NULL; // Start with an empty list

    printf("Creating a linked list...\n");
    
    // Create the list by inserting elements
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);

    // Display the created list
    printf("Displaying the list:\n");
    displayList(head);

    return 0;
}
