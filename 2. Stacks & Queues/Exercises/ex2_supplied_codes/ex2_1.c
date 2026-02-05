// Exercise 3 Stacks and Queues (Spring 2022)
// 1. Write a program to implement a stack using singly linked list.
//
// Implement the program by completing the functions in this supplied code.
#include <stdio.h>
#include <stdlib.h>

//declare linked list node for stack
struct node
{
    //data is a character
    //we will build the parenthese checker on the top of this stack
    char data;
    struct node *next;
};

//the address of the top of the stack
struct node *top = NULL;

//declare the functions for the common operations on stack

//push a new data into the stack
//parameters:
//      *t: the pointer points to the address of the top of the stack
//      v: the value to be pushed into the stack
//return: the pointer points to the address of the current top of the stack
struct node *push(struct node *t, char v);
//pop data from the stack
//parameters:
//      *t: the pointer points to the address of the top of the stack
//return: the pointer points to the address of the current top of the stack
struct node *pop(struct node *t);
//get the topmost data element of the stack
//parameters:
//      *t: the address of the top of the stack
//return: the topmost data element in the stack
char peek(struct node *t);
//display all the data elements in the stack
//parameters:
//      *t: the pointer points to address of the top of the stack
void display(struct node *t);

int main()
{
    //option: operation request from ueser input
    //val: data value
    char val;
    int option;

    do
    {
        printf("\n\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter the character to be pushed on stack ");
                scanf(" %c", &val);
                printf("\n You entered: %c\n", val);
                //TO DO: implement the PUSH operation
                top = push(top, val);
                break;

            case 2:
                //TO DO: implement the POP operation
                top = pop(top);
                break;

            case 3:
                //TO DO: implement the PEEK operation
                val = peek(top);
                if(val != -1)
                    printf("\n The value at the top of stack is : %c", val);
                break;

            case 4:
                //TO DO: : implement the DISPLAY operation
                display(top);
                break;
        }
    //while not choose to exit
    }while(option != 5);

    return 0;
}



//TODO: implement the functions for the common operations on stack
//
// - [X] Push
// - [X] Pop
// - [X] Peek
// - [X] Display

struct node *push(struct node *t, char v)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = v;
    new_node->next = t;
    return new_node;
}

struct node *pop(struct node *t)
{
    if (t == NULL) {
        printf("Stack is empty.\n");
        return t;
    }
    printf("Popping: %c\n", t->data);
    struct node *ptr = t->next;
    free(t);
    if (ptr == NULL) {
        printf("Stack is now empty.\n");
    }
    return ptr;
}

char peek(struct node *t)
{
    return t->data;
}

void display(struct node *t)
{
    if (t == NULL) {
        printf("Stack is empty.\n");
    }
    else while (t != NULL) {
        printf("%c\n", t->data);
        t = t->next;
    }
}
