#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, float val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = stack->top;
    stack->top = newNode;
}

float pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return 0;
    }

    float val = stack->top->val;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return val;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

float eval(float a, char op, float b) {
    float res;
    switch (op) {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    case '%':
        res = (int)a % (int)b;
        break;
    default:
        res = 0;
    }
    return res;
}

float evalPostfix(char *s) {
    Stack st = {NULL};
    int idx = 0;

    while (s[idx] != '\0') {
        if (isdigit(s[idx])) {
            push(&st, s[idx] - '0'); 
        } else {
            float op2 = pop(&st);
            float op1 = pop(&st);
            float result = eval(op1, s[idx], op2);
            push(&st, result);
        }
        idx++;
    }

    return pop(&st);
}

int main() {
    char expression[] = "23*54*+9-";
    float result = evalPostfix(expression);

    printf("Postfix Expression: %s\n", expression);
    printf("Evaluation Result: %.2f\n", result);

    return 0;
}
