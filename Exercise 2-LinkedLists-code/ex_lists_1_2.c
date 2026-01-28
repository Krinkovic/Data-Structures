// Exercise: Linked Lists (TDRK12 Spring 2025)
// Task 1 . Write a program to create a linked list.
// Task 2. Display the linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *display(struct node *);

int main()
{
    struct node *new_node, *ptr;

    int num;
    printf("\nCreating a list.");
    printf("\nEnter the data for a new node (-1 to end) : ");

    scanf("%d", &num);
    while (num != -1)
    {
        //with typecasting, which is needed in C++ .
        //new_node = (struct node *)malloc(sizeof(struct node));

        //without typecasting, it is valid for C standards including C89/90/99.
        new_node = malloc(sizeof(struct node));
        //Don't forget to allocate memory or initialize the pointer to NULL. 
        //If you get the error message 'Segmentation fault,' it is usually related to a pointer issue.

        new_node->data = num;
        //the linked list is empty.
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        //the linked list is not empty.
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }

        printf("\n Enter the data for a new node (-1 to end) : ");
        scanf("%d", &num);
    }

    printf("\n The linked list is created.\n");

    display(start);
}


struct node *display(struct node *start)
{
    if(start == NULL){
        printf("EMPTY LINKED LIST!\n");
        //to be safe, always return start for the current list.
        return start;
    
    }else{   
    
        struct node *ptr;
        ptr = start;
        while (ptr != NULL)
        {
            // Print data with or without the arrow based on whether it's the last node.
            if(ptr->next == NULL)
                printf("%d", ptr->data);
            else
                printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }

    
    return start;
}
