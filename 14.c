#include <stdio.h>
#define MAX 3

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull())
        printf("Stack Overflow! Cannot push %d\n", value);
    else {
        stack[++top] = value;
        printf("%d pushed successfully\n", value);
    }
}

void pop() {
    if (isEmpty())
        printf("Stack Underflow! Cannot pop\n");
    else
        printf("%d popped successfully\n", stack[top--]);
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40); // Overflow check

    pop();
    pop();
    pop();
    pop(); // Underflow check

    return 0;
}
