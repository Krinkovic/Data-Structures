// 2025 Kristoffer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

typedef struct node {
  char value[32];
  struct node *next;
} node;

typedef struct queue {
  node *front;
  node *rear;
} *Queue;

Queue queue_create(void)
{
  Queue new_queue = malloc(sizeof(*new_queue));
  if (new_queue == NULL) {
    return NULL;
  }
  new_queue->front = NULL;
  new_queue->rear = NULL;
  return new_queue;
}

void queue_destroy(Queue q)
{
  node *temp;
  while (q->front != NULL) {
    temp = q->front;
    q->front = q->front->next;
    free(temp);
  }
  free(q);
}

int queue_is_empty(Queue q)
{
  if (q->front == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void queue_enqueue(Queue q, const char *id)
{
  node *new_job = malloc(sizeof(*new_job));
  new_job->next = NULL;
  strcpy(new_job->value, "");
  strcpy(new_job->value, id);
  if (q->front == NULL) {
    q->front = new_job;
    q->rear = new_job;
  } else {
    q->rear->next = new_job;
    q->rear = new_job;
  }
}

int queue_dequeue(Queue q, char *out, int out_size)
{
  node *temp;
  if (q->front == NULL) {
    return 0;
  }
  strncpy(out, q->front->value, out_size);
  temp = q->front;
  q->front = q->front->next;
  free(temp);
  return 1;
}

int queue_front(Queue q, char *out, int out_size)
{
  if (q->front == NULL) {
    return 0;
  }
  strncpy(out, q->front->value, out_size);
  return 1;
}

void queue_print(Queue q)
{
  int i = 1;
  node *ptr = q->front;
  if (ptr == NULL) {
    puts("\nQueue is empty.");
  } else {
    puts("\nQueue:");
  }
  while (ptr != NULL) {
    printf("%d) %s\n",i, ptr->value);
    i += 1;
    ptr = ptr->next;
  }
  puts("");
}
