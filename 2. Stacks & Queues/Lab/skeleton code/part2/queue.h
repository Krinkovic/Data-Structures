#ifndef QUEUE_H
#define QUEUE_H

/*
 * Queue ADT for managing print jobs.
 *
 * A job is represented by a short string identifier (e.g., "J1", "jobA").
 * Students must implement this interface in queue.c using either:
 *   - a linked-list queue, or
 *   - a circular-array queue.
 *
 * The main program for Part 2 depends on these operations.
 */

typedef struct queue *Queue;

/*
 * Create and return a new empty queue.
 * Return NULL if memory allocation fails.
 */
Queue queue_create(void);

/*
 * Free all memory associated with the queue.
 * After calling this function, the queue must not be used again.
 */
void queue_destroy(Queue q);

/*
 * Return non-zero (true) if the queue is empty.
 */
int queue_is_empty(Queue q);

/*
 * Add a new job id to the rear of the queue.
 * 'id' is a string (e.g., "J1").
 */
void queue_enqueue(Queue q, const char *id);

/*
 * Remove the job at the front of the queue and copy its identifier
 * into the buffer 'out' (with size 'out_size').
 *
 * Return non-zero on success.
 * Return 0 if the queue is empty.
 */
int queue_dequeue(Queue q, char *out, int out_size);

/*
 * Copy (but do not remove) the identifier of the front job into 'out'.
 * Return non-zero on success.
 * Return 0 if the queue is empty.
 */
int queue_front(Queue q, char *out, int out_size);

/*
 * Print all job identifiers from front to rear.
 * Format is up to the implementer (e.g., "Queue: J1 J2 J3").
 */
void queue_print(Queue q);

#endif
