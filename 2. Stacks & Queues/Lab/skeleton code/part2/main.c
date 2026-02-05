#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include "queue.h"



int main(void) {
    Queue q = queue_create();

    if (q == NULL) {
        fprintf(stderr, "Error: could not create queue.\n");
        return 1;
    }

    char cmd[16];
    char id[32];

    printf("Commands:\n");
    printf("  arrive <id>  - add new print job\n");
    printf("  serve        - serve job at the front\n");
    printf("  peek         - show job at the front\n");
    printf("  print        - show all jobs\n");
    printf("  exit         - quit\n\n");

    while (1) {
        printf("> ");

        if (scanf("%15s", cmd) != 1) {
            break;
        }

        if (strcmp(cmd, "arrive") == 0) {

            if (scanf("%31s", id) != 1) {
                printf("Error: expected a job id.\n");
                continue;
            }

            queue_enqueue(q, id);
            printf("Job %s arrived.\n", id);

        } else if (strcmp(cmd, "serve") == 0) {

            if (queue_is_empty(q)) {
                printf("No jobs to serve.\n");

            } else {

                queue_dequeue(q, id, 32);
                printf("Serving: %s\n", id);
            }

        } else if (strcmp(cmd, "peek") == 0) {

            if (queue_is_empty(q)) {
                printf("Queue is empty.\n");
            } else {

                queue_front(q, id, 32);
                printf("\nFront: %s\n\n", id);
            }

        } else if (strcmp(cmd, "print") == 0) {

            queue_print(q);

        } else if (strcmp(cmd, "exit") == 0) {
            break;

        } else {
            printf("Unknown command: %s\n", cmd);
            printf("Valid commands: arrive <id>, serve, peek, print, exit\n");
        }
    }

    queue_destroy(q);
    return 0;
}
