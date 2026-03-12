// file: include/task.h
#ifndef TASK_H
#define TASK_H

typedef struct {
    int id;             // unique task id
    int pages;          // number of pages
    int arrival_index;  // order in which the task arrived
} Task;

/**
 * Create a Task value.
 * You may simply fill the struct fields.
 */
Task task_create(int id, int pages, int arrival_index);

/**
 * Compare two tasks according to the lab rules:
 *  - primary key: pages (fewer pages = higher priority)
 *  - tie-breaker: arrival_index (smaller = higher priority)
 *
 * Return:
 *  < 0 if a has higher priority than b (a "smaller" key)
 *    0 if they are equal
 *  > 0 if b has higher priority than a
 */
int task_compare(Task a, Task b);

/**
 * Print a single task in a human-readable format.
 * Example format (you can choose your own):
 *  Task ID: 1, Pages: 10, Arrival Index: 1
 */
void task_print(const Task *t);

#endif // TASK_H