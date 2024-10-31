#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// FIFO Queue
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

int isEmpty(Queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

int size(Queue *q)
{
    Node *temp = q->front;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue *q)
{
    int data = 0;
    printf(">> Enter the data to be inserted into the queue: ");
    scanf("%d", &data);
    Node *newNode = createNode(data);
    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf(">> %d added to the queue at position %d.\n", data, size(q));
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue Underflow\n");
        return;
    }
    Node *temp = q->front;
    q->front = temp->next;
    if (q->front == NULL)
        q->rear = NULL;
    printf(">> %d dequeued from the queue, %d elements remaining.\n", temp->data, size(q) - 1);
    free(temp);
}

void peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue is empty\n");
    }
    else
    {
        printf(">> Front element: %d\n", q->front->data);
    }
}

void back(Queue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue is empty\n");
    }
    else
    {
        printf(">> Rear element: %d\n", q->rear->data);
    }
}

void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue is empty\n");
        return;
    }

    Node *temp = q->front;
    printf("Queue: Front -> ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL)
        {
            printf(" -> ");
        }
    }
    printf(" <- Rear\n");
}

int main()
{
    Queue q = {NULL, NULL};
    int choice;

    while (1)
    {
        printf("\n\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Back (Rear)\n");
        printf("5. Check if Empty\n");
        printf("6. Queue Size\n");
        printf("7. Print Queue\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            back(&q);
            break;
        case 5:
            if (isEmpty(&q))
                printf(">> Queue is empty\n");
            else
                printf(">> Queue is not empty\n");
            break;
        case 6:
            printf(">> Queue size: %d\n", size(&q));
            break;
        case 7:
            printQueue(&q);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
