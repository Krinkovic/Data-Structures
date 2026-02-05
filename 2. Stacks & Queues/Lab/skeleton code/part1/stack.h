#ifndef STACK_H
#define STACK_H

/*
 * Stack ADT for characters.
 *
 * You will implement this interface in stack.c using either:
 *   - an array-based stack, or
 *   - a linked-list-based stack.
 *
 * The main program (Undo/Redo application) relies on these operations.
 */

typedef struct stack *Stack;

/*
 * Create and return a new empty stack.
 * Return NULL if memory allocation fails.
 */
Stack stack_create(void);

/*
 * Free all memory associated with the stack.
 * After calling this function, the stack is no longer usable.
 */
void stack_destroy(Stack s);

/*
 * Return non-zero (true) if the stack is empty.
 * Return zero (false) otherwise.
 */
int stack_is_empty(Stack s);

/*
 * Push a character onto the stack.
 * If the stack is full (array version) or memory allocation fails (linked version),
 * print an error message or handle it appropriately.
 */
void stack_push(Stack s, char value);

/*
 * Remove the top character from the stack and return it.
 * Precondition: the stack is not empty.
 */
char stack_pop(Stack s);

/*
 * Return (but do not remove) the top character on the stack.
 * Precondition: the stack is not empty.
 */
char stack_top(Stack s);

/*
 * Print entire stack
 * Precondition: the stack is not empty.
 */
void stack_print(Stack s);

#endif
