// Exercise 3 Stacks and Queues (Spring 2022)
// 1. Write a program to implement a stack using singly linked list.
//
// Implement the program by completing the functions in this supplied code.
#include <stdio.h>
#include <stdlib.h>

//declare linked list node for stack
struct node
{
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
                top = push(top, val);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                val = peek(top);
                if(val != -1)
                    printf("\n The value at the top of stack is : %c", val);
                break;

            case 4:
                display(top);
                break;
        }
    //while not choose to exit
    }while(option != 5);

    return 0;
}


struct node *push(struct node *top, char val){

    //create new node
    struct node *ptr;
    ptr = malloc(sizeof(struct node));
    ptr->data =val;

    //when the stack is empty
    if(top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else{
        ptr->next = top;
        top = ptr;
    }

    return top;
}

struct node *pop(struct node *top){

    //ptr is used to free the current topmost element in the stack
    struct node *ptr;
    ptr = top;

    if(top == NULL)
        printf("\n STACK UNDERFLOW");
    else{
        top = top->next;
        printf("\n The value being deleted is : %c", ptr->data);
        free(ptr);
    }

    return top;
}

char peek(struct node *top){

    if(top == NULL){
        printf("\n STACK UNDERFLOW");
        return -1;
    }else{
        return top->data;
    }
}

void display(struct node *top){

    struct node *ptr;
    ptr = top;

    if(top == NULL)
        printf("\n STACK IS EMPTY");
    else{
        printf("\n");
        while(ptr != NULL){
            printf("%c \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

