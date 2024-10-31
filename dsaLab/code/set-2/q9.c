#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = NULL;
}

void push(Stack *stack, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        return -1; 
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

void initializeQueue(Queue *queue) {
    initializeStack(&queue->stack1);
    initializeStack(&queue->stack2);
}

void enqueue(Queue *queue, int data) {
    push(&queue->stack1, data);
    printf(">> %d enqueued to the queue\n", data);
}

int dequeue(Queue *queue) {
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            int data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }
    return pop(&queue->stack2);
}

void displayQueue(Queue *queue) {
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue is empty\n");
        return;
    }

    Stack tempStack;
    initializeStack(&tempStack);

    while (!isEmpty(&queue->stack2)) {
        int data = pop(&queue->stack2);
        printf("%d ", data);
        push(&tempStack, data);
    }

    while (!isEmpty(&queue->stack1)) {
        int data = pop(&queue->stack1);
        push(&tempStack, data);
    }

    while (!isEmpty(&tempStack)) {
        int data = pop(&tempStack);
        push(&queue->stack1, data);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data == -1) {
                    printf("Queue underflow\n");
                } else {
                    printf(">> %d dequeued from the queue\n", data);
                }
                break;
            case 3:
                printf("Queue contents: ");
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
