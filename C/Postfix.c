#include <stdio.h>
#include <string.h>

void push(char *stack, int *top, char item);
void postfix(char *expression, int top);

int main() {
    char exp[100];

    printf("Enter the postfix expression: ");
    fgets(exp, 100, stdin);

    postfix(exp, strlen(exp));
    return 0;
}

void postfix(char *expression, int top) {
    // Adding Bracket at the end
    if (expression[top - 1] != ')') {
        top++;
        expression[top - 1] = ')';
    }
    // Creating an empty stack
    char stack[top];
    int stack_top = -1;

    int i = 0;
    char A, B;
    while (expression[i] != ')') {
        switch (expression[i]) {
            case '*':
            case '+':
            case '-':
            case '/':
                A = stack[stack_top--];
                B = stack[stack_top--];
                printf("%c%c%c", B, expression[i], A);
                break;
            default:
                push(stack, &stack_top, expression[i]);
                break;
        }
        i++;
    }
}

void push(char *stack, int *top, char item) {
    (*top)++;
    stack[*top] = item;
}
