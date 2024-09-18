#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void peek();
void display();
typedef struct Node {
  int val;
  struct Node *next;
} Node;
Node *head = NULL;
Node *top = NULL;

int main() {
  int choice = 0;
  while (choice != 5) {
    printf("\n\nChose one from the below options...\n");
    printf("\n1.Push\n2.Pop\n3.Peek\n4.display\n5.exit\n");
    printf("\n>>Enter your choice :");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      push();
      break;
    }
    case 2: {
      pop();
      break;
    }
    case 3: {
      peek();
      break;
    }
    case 4: {
      display();
      break;
    }
    case 5: {
      printf("Exiting....");
      break;
    }
    default: {
      printf("Please Enter valid choice ");
    }
    };
  }
  return 0;
}
void push() {
  int val;
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("not able to push the element");
  } else {
    printf("Enter the value :");
    scanf("%d", &val);
    if (head == NULL) {
      head = newNode;
    } else {
      top->next = newNode;
    }

    newNode->next = NULL;
    newNode->val = val;
    top = newNode;
    printf("%d  pushed", val);
  }
}

void pop() {
  int item;
  Node *temp = head;

  if (head == NULL) {
    printf("Underflow");
  } else {
    while (temp->next != top) {
      temp = temp->next;
    }
    item = top->val;
    temp->next = NULL;
    free(top);
    top = temp;
    printf("%d popped", item);
  }
}

void display() {
  Node *temp = head;
  if (temp == NULL) {
    printf("Stack is empty\n");
  } else {
    printf("Printing Stack elements \n");
    while (temp != NULL) {
      printf("| %d |\n", temp->val);
      temp = temp->next;
    }
  }
}

void peek() {
  if (top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  printf("| %d |\n", top->val);
}
