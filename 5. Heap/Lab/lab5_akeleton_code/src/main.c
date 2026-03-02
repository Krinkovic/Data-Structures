// file: src/main.c
// 2026 Kristoffer

// This is the main application file for the printer task manager.
//
// Please fill in the TODO sections that call the priority queue ADT functions.
// No other modifications are required.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "priority_queue.h"

#define MAX_LINE 100
#define DEFAULT_CAPACITY 100

int main(void)
{
    /* TODO: create the priority queue using pq_create */
    PriorityQueue *pq = NULL;   // replace with pq_create(DEFAULT_CAPACITY)

    if (!pq) {
        fprintf(stderr, "Error: could not create priority queue.\n");
        return 1;
    }

    char line[MAX_LINE];
    int next_task_id = 1;
    int next_arrival_index = 1;

    printf("Printer Task Manager (Priority Queue using Min-Heap)\n");
    printf("Commands:\n");
    printf("  add <pages>\n");
    printf("  serve\n");
    printf("  peek\n");
    printf("  print\n");
    printf("  exit\n");

    while (1) {
        printf("> ");
        // Read a line of input safely using fgets
        if (!fgets(line, sizeof(line), stdin))
            break;

        line[strcspn(line, "\n")] = '\0';  // strip newline

        /* -------------------- ADD -------------------- */
        if (strncmp(line, "add ", 4) == 0) {

            int pages;
            if (sscanf(line + 4, "%d", &pages) != 1 || pages <= 0) {
                printf("Error: invalid pages value.\n");
                continue;
            }

            Task t = task_create(next_task_id, pages, next_arrival_index);

            /* TODO: insert the task into the priority queue using pq_insert */
            int result = 0;    //  replace with pq_insert(pq, t)

            if (/* check if result indicates overflow */ result != 0) {
                printf("Error: priority queue overflow.\n");
            } else {
                printf("Added ");
                task_print(&t);
                printf("\n");

                /* TODO: increment next_task_id and next_arrival_index */

            }

        /* -------------------- SERVE -------------------- */
        } else if (strcmp(line, "serve") == 0) {

            Task t;

            /* TODO: call pq_extract_min to get the next task */
            int result = -1;   //  replace with pq_extract_min(pq, &t)

            if (/* check if queue was empty */ result != 0) {
                printf("Error: priority queue is empty.\n");
            } else {
                printf("Serving: ");
                task_print(&t);
                printf("\n");
            }

        /* -------------------- PEEK -------------------- */
        } else if (strcmp(line, "peek") == 0) {

            Task t;

            /* TODO: call pq_peek to view next task */
            int result = -1;   //  replace with pq_peek(pq, &t)

            if (/* check if queue was empty */ result != 0) {
                printf("Error: priority queue is empty.\n");
            } else {
                printf("Front: ");
                task_print(&t);
                printf("\n");
            }

        /* -------------------- PRINT -------------------- */
        } else if (strcmp(line, "print") == 0) {

            /* TODO: call pq_print to show all tasks */
            // pq_print(pq);

        /* -------------------- EXIT -------------------- */
        } else if (strcmp(line, "exit") == 0) {
            break;

        } else if (line[0] == '\0') {
            continue;
        } else {
            printf("Unknown command. Valid commands are: add, serve, peek, print, exit.\n");
        }
    }

    /* TODO: destroy the priority queue */
    // pq_destroy(pq);

    return 0;
}
