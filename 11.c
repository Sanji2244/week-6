#include <stdio.h>
#define MAX 5  // Maximum size of stack

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow! Cannot push %d\n", value);
    else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow! Nothing to pop\n");
    else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    push(40);
    push(50);
    push(60); // Overflow check
    display();

    return 0;
}
