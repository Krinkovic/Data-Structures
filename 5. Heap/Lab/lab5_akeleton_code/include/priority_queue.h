// file: include/priority_queue.h
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "task.h"

// Opaque type; defined in the .c file
typedef struct PriorityQueue PriorityQueue;

/**
 * Create a priority queue with the given capacity.
 * Returns NULL on allocation failure.
 */
PriorityQueue *pq_create(int capacity);

/**
 * Free all resources associated with the priority queue.
 */
void pq_destroy(PriorityQueue *pq);

/**
 * Return non-zero if the priority queue is empty, 0 otherwise.
 */
int pq_is_empty(const PriorityQueue *pq);

/**
 * Return non-zero if the priority queue is full, 0 otherwise.
 * (Only meaningful if you use a fixed-size array.)
 */
int pq_is_full(const PriorityQueue *pq);

/**
 * Insert a task into the priority queue (min-heap).
 * Return 0 on success, non-zero on error (e.g., overflow).
 */
int pq_insert(PriorityQueue *pq, Task task);

/**
 * Copy the minimum (highest-priority) task into *out
 * without removing it from the heap.
 * Return 0 on success, non-zero if the queue is empty.
 */
int pq_peek(const PriorityQueue *pq, Task *out);

/**
 * Remove the minimum (highest-priority) task from the heap
 * and copy it into *out.
 * Return 0 on success, non-zero if the queue is empty.
 */
int pq_extract_min(PriorityQueue *pq, Task *out);

/**
 * Print all tasks in the priority queue from highest to lowest
 * priority, in a human-readable format.
 * The order does not need to reflect the internal array layout.
 */
void pq_print(const PriorityQueue *pq);

#endif // PRIORITY_QUEUE_H