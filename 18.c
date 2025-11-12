#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char *exp) {
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", exp);

    printf("Prefix Evaluation Result: %d\n", evaluatePrefix(exp));
    return 0;
}
