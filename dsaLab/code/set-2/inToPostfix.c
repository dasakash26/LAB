
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char val;
  struct Node *next;
} Node;

Node *top = NULL;

void push(char val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = top;
  top = newNode;
}

char pop() {
  if (top == NULL) {
    printf("stack underflow\n");
    return -1;
  }

  char val = top->val;
  Node *temp = top->next;
  free(top);
  top = temp;
  return val;
}

char peek() {
  if (top == NULL) {
    return -1;
  }
  return top->val;
}

int isEmpty() { return top == NULL; }

int precedence(char op) {
  if (op == '^') {
    return 3;
  } else if (op == '*' || op == '/' || op == '%') {
    return 2;
  } else if (op == '+' || op == '-') {
    return 1;
  } else {
    return 0;
  }
}

int isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
          ch == '^');
}

char *inToPostfix(char *s) {
  char *res = (char *)malloc(100 * sizeof(char));
  int r = 0;
  int i = 0;

  while (s[i] != '\0') {
    if (isalnum(s[i])) {
      res[r++] = s[i];
    } else if (s[i] == '(') {
      push(s[i]);
    } else if (s[i] == ')') {
      while (!isEmpty() && peek() != '(') {
        res[r++] = pop();
      }
      pop();
    } else if (isOperator(s[i])) {
      while (!isEmpty() && precedence(peek()) >= precedence(s[i])) {
        res[r++] = pop();
      }
      push(s[i]);
    }
    i++;
  }

  while (!isEmpty()) {
    res[r++] = pop();
  }

  res[r] = '\0';
  return res;
}

int main() {
  char expression[] = "a+b*(c^d-e)";
  char *postfix = inToPostfix(expression);

  printf("Infix: %s\n", expression);
  printf("Postfix: %s\n", postfix);

  free(postfix);
  return 0;
}
