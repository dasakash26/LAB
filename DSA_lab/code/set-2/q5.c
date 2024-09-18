#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

// Function prototypes
void insertAtPosition(Node **head, int position, int value);
void deleteAtPosition(Node **head, int position);
void countNodes(Node *head);
void reversePrint(Node *head);
void reverseList(Node **head);
void printList(Node *head);

// Main function
int main() {
    Node *head = NULL;
    
    // Insert nodes
    insertAtPosition(&head, 1, 10);
    insertAtPosition(&head, 2, 20);
    insertAtPosition(&head, 3, 30);
    insertAtPosition(&head, 4, 40);
    
    printf("Original list:\n");
    printList(head);

    printf("Number of nodes:\n");
    countNodes(head);

    printf("Reverse print:\n");
    reversePrint(head);

    printf("Reversing the list:\n");
    reverseList(&head);
    printList(head);

    printf("Deleting node at position 2:\n");
    deleteAtPosition(&head, 2);
    printList(head);

    return 0;
}

// Function to insert a node at a specified position
void insertAtPosition(Node **head, int position, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                printf("Position out of bounds\n");
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from a specified position
void deleteAtPosition(Node **head, int position) {
    Node *temp = *head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 1; i < position; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return;
        }
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to count the number of nodes in the linked list
void countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Count: %d\n", count);
}

// Function to print the list in reverse order
void reversePrint(Node *head) {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("| %d |\n", temp->val);
        temp = temp->prev;
    }
}

// Function to reverse the entire list
void reverseList(Node **head) {
    Node *temp = NULL;
    Node *current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to print the list
void printList(Node *head) {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("| %d | ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

