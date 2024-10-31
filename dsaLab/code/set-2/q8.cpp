#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct CircularQueue
{
    Node *front;
    Node *rear;
} CircularQueue;

void initializeQueue(CircularQueue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(CircularQueue *q)
{
    return (q->front == NULL);
}

void enqueue(CircularQueue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q))
        q->front = newNode;
    else
        q->rear->next = newNode;
    q->rear = newNode;
    q->rear->next = q->front;
    printf(">> %d added to the queue.\n", data);
}

void dequeue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue Underflow! No elements to dequeue.\n");
        return;
    }

    Node *temp = q->front;
    int data = temp->data;

    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    free(temp);
    printf(">> %d dequeued from the queue.\n", data);
}

void peek(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue is empty.\n");
    }
    else
    {
        printf(">> Front element: %d\n", q->front->data);
    }
}

void back(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue is empty.\n");
    }
    else
    {
        printf(">> Rear element: %d\n", q->rear->data);
    }
}

void printQueue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf(">> Queue is empty.\n");
        return;
    }

    Node *temp = q->front;
    printf("Queue: Front -> ");
    do
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != q->front)
        {
            printf(" -> ");
        }
    } while (temp != q->front);
    printf(" <- Rear\n");
}

int main()
{
    CircularQueue q;
    initializeQueue(&q);
    int choice, data;

    while (1)
    {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Back (Rear)\n");
        printf("5. Print Queue\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            enqueue(&q, data);
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
            printQueue(&q);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
