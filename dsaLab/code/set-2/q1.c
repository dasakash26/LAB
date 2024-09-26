#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node *createNode(int element) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = element;

  newNode->next = NULL;
  return newNode;
}

Node *createLinkedList() {
  int size = 0;
  printf("Enter the initial size of the linked list: ");
  scanf("%d", &size);
  Node *head = NULL;
  Node *tail = NULL;
  Node *temp = NULL;

  for (int i = 1; i <= size; i++) {
    int element;
    printf("Enter the element [%d]: ", i);
    scanf("%d", &element);
    temp = createNode(element);
    if (head == NULL) {
      head = temp;
    } else {
      tail->next = temp;
    }
    tail = temp;
  }
  return head;
}

int len(Node *head, int print) {
  Node *temp = head;
  int cnt = 0;
  while (temp != NULL) {
    cnt++;
    temp = temp->next;
  }
  if (print) {
    printf("The length of the linked list is: %d\n", cnt);
  }
  return cnt;
}

void insert(Node **phead) {
  int pos = 0;
  int element = 0;
  printf("Enter the position to insert: ");
  scanf("%d", &pos);
  printf("Enter the element to insert: ");
  scanf("%d", &element);
  int length = len(*phead, 0);
  if (pos < 1 || pos > length + 1) {
    printf("Invalid position!!\n");
  } else if (pos == 1) {
    Node *temp = createNode(element);
    temp->next = *phead;
    *phead = temp;
  } else {
    Node *temp = *phead;
    for (int i = 1; i < pos - 1; i++) {
      temp = temp->next;
    }
    Node *newNode = createNode(element);
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void printLinkedList(Node *head) {
  Node *temp = head;
  printf(">>> ");
  while (temp != NULL) {
    printf("%d -> ", temp->val);
    temp = temp->next;
  }
  printf("NULL\n");
}

void delete (Node **phead) {
  int pos = 0;
  printf("Enter the position to delete: ");
  scanf("%d", &pos);
  int length = len(*phead, 0);
  Node *temp = *phead;

  if (*phead == NULL) {
    printf("Empty list!!");
  } else if (pos < 1 || pos > length) {
    printf("Invalid position!!\n");
  } else if (pos == 1) {
    *phead = (temp)->next;
    free(temp);
  } else {
    Node *prev = NULL;
    for (int i = 1; i < pos - 1; i++) {
      prev = temp;
      temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
  }
}

int main() {
  Node *list = createLinkedList();
  printLinkedList(list);
  int choice;
  do {
    printf("\nMENU\n");
    printf("1. Insert Element\n");
    printf("2. Print Linked List\n");
    printf("3. Display Length\n");
    printf("4. Delete Element\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      insert(&list);
      break;
    case 2:
      printLinkedList(list);
      break;
    case 3:
      len(list, 1);
      break;
    case 4:
      delete (&list);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 5);

  return 0;
}
