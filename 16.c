// infix -> prefix conversion
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void infixToPrefix(char infix[]) {
    char prefix[MAX], temp[MAX];
    int i, j = 0;

    reverse(infix); // Step 1

    // Step 2: Swap '(' and ')'
    for (i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 3: Convert to postfix (on reversed infix)
    for (i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c))
            temp[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                temp[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(c))
                temp[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        temp[j++] = pop();

    temp[j] = '\0';
    reverse(temp); // Step 4

    printf("Prefix Expression: %s\n", temp);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix);
    return 0;
}
