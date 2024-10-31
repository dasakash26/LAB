#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  char val;
  struct Node *next;
} Node;

typedef struct Stack
{
  Node *top;
} Stack;

void push(Stack *stack, char val)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = stack->top;
  stack->top = newNode;
}

char pop(Stack *stack)
{
  if (stack->top == NULL)
  {
    printf("Stack underflow\n");
    return '\0';
  }

  char val = stack->top->val;
  Node *temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return val;
}

char peek(Stack *stack)
{
  if (stack->top == NULL)
  {
    return '\0';
  }
  return stack->top->val;
}

int isEmpty(Stack *stack)
{
  return stack->top == NULL;
}

int precedence(char op)
{
  if (op == '^')
  {
    return 3;
  }
  else if (op == '*' || op == '/' || op == '%')
  {
    return 2;
  }
  else if (op == '+' || op == '-')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

char *inToPostfix(char *s)
{
  Stack stack = {NULL};
  char *res = (char *)malloc(100 * sizeof(char));
  int r = 0;
  int i = 0;

  while (s[i] != '\0')
  {
    if (isalnum(s[i]))
    {
      res[r++] = s[i];
    }
    else if (s[i] == '(')
    {
      push(&stack, s[i]);
    }
    else if (s[i] == ')')
    {
      while (!isEmpty(&stack) && peek(&stack) != '(')
      {
        res[r++] = pop(&stack);
      }
      pop(&stack);
    }
    else if (isOperator(s[i]))
    {
      while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(s[i]))
      {
        res[r++] = pop(&stack);
      }
      push(&stack, s[i]);
    }
    i++;
  }

  while (!isEmpty(&stack))
  {
    res[r++] = pop(&stack);
  }

  res[r] = '\0';
  return res;
}

int main()
{
  char expression[] = "a+b*(c^d-e)";
  char *postfix = inToPostfix(expression);

  printf("Infix: %s\n", expression);
  printf("Postfix: %s\n", postfix);

  free(postfix);
  return 0;
}
