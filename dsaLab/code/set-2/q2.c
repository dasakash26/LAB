#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

Node *createLinkedList() {
  int size = 0;
  printf("Enter the size of the linked list :");
  scanf("%d", &size);

  Node *head = NULL;
  Node *temp = NULL;
  Node *tail = NULL;

  for (int i = 1; i <= size; i++) {
    int val = 0;
    printf("Enter the value for node -> %d :", i);
    scanf("%d", &val);

    temp = createNode(val);

    if (head == NULL) {
      head = temp;
    } else {
      tail->next = temp;
    }
    tail = temp;
  }
  tail->next = head;
  return head;
}

void printLinkedList(Node *head) {
  Node *temp = head;
  printf(">>> ");
  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("Head\n");
}

int Josephus(Node *head) {
  int k;
  printf("Enter the value of k : ");
  scanf("%d", &k);

  Node *temp = head;
  Node *prev = NULL;

  while (temp->next != head) {
    prev = temp;
    temp = temp->next;
  }

  while (temp->next != temp) {
    for (int i = 0; i < k - 1; i++) {
      prev = temp;
      temp = temp->next;
    }
    printf(">> %d is eliminated.\n", temp->data);
    prev->next = temp->next;
    free(temp);
    temp = prev->next;
  }

  return temp->data;
}

int main() {
  // code
  Node *list = createLinkedList();

  printLinkedList(list);
  int result = Josephus(list);
  printf("Applying Josephus problem: \n");
  printLinkedList(list);
  free(list);
  return 0;
}
