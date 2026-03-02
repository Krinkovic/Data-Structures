// file: src/priority_queue_heap.c
// 2026 Kristoffer

#include <stdio.h>
#include <stdlib.h>
#include "../include/priority_queue.h"
#include "../include/task.h"

struct PriorityQueue {
    Task *data;     // array-based min-heap
    int size;
    int capacity;
};

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2*i + 1)
#define RIGHT(i)  (2*i + 2)

static void heapify_up(PriorityQueue *pq, int index);
static void heapify_down(PriorityQueue *pq, int index);

PriorityQueue* pq_create(int capacity)
{
    // Allocate heap structure and underlying array
    // Initialize size to 0
    // Return NULL on failure
    // (Refer to heap representation slide)
    PriorityQueue *new_heap = malloc(sizeof(*new_heap));
    if (new_heap == NULL) {
        return NULL;
    }
    new_heap->data = malloc((capacity + 1) * sizeof(int));
    new_heap->size = 0;
    new_heap->capacity = capacity;
    return new_heap;
}

void pq_destroy(PriorityQueue *pq)
{
    // Free array + structure
    // Straightforward
    free(pq->data);
    free(pq);
}

int pq_is_empty(const PriorityQueue *pq)
{
    // Return 1 if size == 0
    return pq->size == 0;
}

int pq_is_full(const PriorityQueue *pq)
{
    // Return 1 if size == capacity
    return pq->size == pq->capacity;
}

int pq_insert(PriorityQueue *pq, Task task)
{
    // 1. Add new element at end (like Step 1 in insertion pseudocode)
    // 2. Call heapify_up() to restore heap property
    //
    // Check the pseudocode for insertion in binary heap from lecture slides
    if (pq_is_full(pq) == 1) {
        return -1;
    } else {
        pq->size++;
        pq->data[pq->size] = task;
        heapify_up(pq, pq->size);
        return 0;
    }
}

int pq_peek(const PriorityQueue *pq, Task *out)
{
    // Return the root element (index 0)
    // Error if empty
    if (pq_is_empty(pq) == 1) {
        return -1;
    } else {
        out = &pq->data[1];
        return 0;
    }
}

int pq_extract_min(PriorityQueue *pq, Task *out)
{
    // 1. Save root to *out
    // 2. Move last element to root (Step 1 + Step 2 in deletion pseudocode)
    // 3. Call heapify_down() to restore heap property
    //
    // Refer to deletion in binary heap pseudocode from lecture slides.
    if (pq_is_empty(pq) == 1) {
        return -1;
    } else {
        out = &pq->data[0];
        pq->data[0] = pq->data[pq->size];
        pq->size--;
        heapify_down(pq, 1);
        return 0;
    }
}

void pq_print(const PriorityQueue *pq)
{
    // Print tasks in any consistent format
    // Heap order is acceptable (not sorted)
    if (pq_is_empty(pq) == 1) {
        puts("Queue is empty");
    } else {
        for (int i; i < pq->size; i++) {
            task_print(&pq->data[i]);
        }
    }
}

static void heapify_up(PriorityQueue *pq, int index)
{
    // Implement according to lecture pseudocode for insertion:
    // "Compare with parent; if heap property violated, swap and continue."
    //
    // Use task_compare() to determine priority.
}

static void heapify_down(PriorityQueue *pq, int index)
{
    // Implement according to lecture pseudocode for deletion:
    // "Compare parent with children; swap with smaller child if needed."
    //
    // Use task_compare() for priority comparisons.
}
