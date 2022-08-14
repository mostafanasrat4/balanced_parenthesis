#include <stdio.h>
#define MAX 100

// Stack Implementation
struct stack {
  char stck[MAX];
  int top;
};

void push(struct stack* myStack, char item) {
  if (myStack->top == (MAX - 1))
    printf("Stack is Full\n");

  else {
    myStack->top++;
    myStack->stck[myStack->top] = item;
  }
}

void pop(struct stack* myStack) {
  if (myStack->top == -1)
    printf("Stack is Empty\n");

  else
    myStack->top--;
}