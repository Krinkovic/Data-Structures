// 2025 Kristoffer

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define MAX 10

typedef struct stack {
  char list[MAX];
  int top;
} *Stack;

Stack stack_create(void)
{
  struct stack *new_stack = malloc(sizeof(*new_stack));
  if (new_stack == NULL) {
    return NULL;
  }
  new_stack->top = -1;
  return new_stack;
}

void stack_destroy(Stack s)
{
  free(s);
}

int stack_is_empty(Stack s)
{
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void stack_push(Stack s, char value)
{
  if (s->top == MAX - 1) {
    puts("Stack is full.");
  } else {
    s->top += 1;
    s->list[s->top] = value;
  }
}

char stack_pop(Stack s)
{
  char c;
  if (stack_is_empty(s)) {
    return '\0';
  } else {
    c = s->list[s->top];
    s->top -= 1;
  }
  return c;
}

char stack_top(Stack s)
{
  if (s->top == -1) {
    return '\0';
  }
  return s->list[s->top];
}

void stack_print(Stack s)
{
  if (stack_is_empty(s)) {
    puts("Empty.");
  } else {
    for (int i = s->top; i >= 0; i--) {
      printf("%c\n", s->list[i]);
    }
  }
}
