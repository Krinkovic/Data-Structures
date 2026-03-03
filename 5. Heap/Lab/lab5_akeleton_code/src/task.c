// file: src/task.c
// 2026 Kristoffer

#include <stdio.h>
#include "../include/task.h"

Task task_create(int id, int pages, int arrival_index)
{
    Task t;
    t.id = id;
    t.pages = pages;
    t.arrival_index = arrival_index;
    return t;
}

int task_compare(Task a, Task b)
{
    if (a.pages != b.pages) {
        return a.pages - b.pages;
    } else {
        return a.arrival_index - b.arrival_index;
    }
}

void task_print(const Task *t)
{
    if (!t) {
        return;
    }
    // TODO: adjust the format as you like
    printf("Task %d: %d pages (arrival at %d)\n", t->id, t->pages, t->arrival_index);
}
