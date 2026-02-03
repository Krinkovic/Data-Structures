#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(void) {
    Stack undo = stack_create();
    Stack redo = stack_create();

    if (undo == NULL || redo == NULL) {
        fprintf(stderr, "Error: could not create stacks.\n");
        return 1;
    }

    char cmd[16];
    char c;

    printf("Commands:\n");
    printf("  do <c>   - type character c\n");
    printf("  undo     - undo last character\n");
    printf("  redo     - redo last undone character\n");
    printf("  print    - show Undo and Redo stacks\n");
    printf("  exit     - quit\n\n");

    while (1) {
        printf("> ");

        if (scanf("%15s", cmd) != 1) {
            break;
        }

        if (strcmp(cmd, "do") == 0) {

            if (scanf(" %c", &c) != 1) {
                printf("Error: expected a character after 'do'.\n");
                continue;
            }

            // TODO: push c onto undo stack
            // TODO: clear redo stack (hint: pop until empty)

            printf("Typed: %c\n", c);

        } else if (strcmp(cmd, "undo") == 0) {

            if (stack_is_empty(undo)) {
                printf("Nothing to undo.\n");
            } else {

                // TODO: remove top element from undo stack
                // TODO: push it onto redo stack
                // char ch = ...;

                printf("Undo: removed %c\n", ch);
            }

        } else if (strcmp(cmd, "redo") == 0) {

            if (stack_is_empty(redo)) {
                printf("Nothing to redo.\n");
            } else {

                // TODO: remove top element from redo stack
                // TODO: push it onto undo stack
                // char ch = ...;

                printf("Redo: restored %c\n", ch);
            }

        } else if (strcmp(cmd, "print") == 0) {

            // TODO: print both Undo and Redo stacks
            // (students may write a helper print function)

        } else if (strcmp(cmd, "exit") == 0) {
            break;

        } else {
            printf("Unknown command: %s\n", cmd);
            printf("Valid commands: do <c>, undo, redo, print, exit\n");
        }
    }

    stack_destroy(undo);
    stack_destroy(redo);

    return 0;
}
