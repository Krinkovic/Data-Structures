// Exercise: Linked Lists (TDRK12 Spring 2025)
// If you like to use typedef to define the structure for node

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int data;
    struct data *next;
    
}node;


int main()
{
    node *new_node;

    new_node = malloc(sizeof(node));
    
    new_node->data = 5;
    new_node->next = NULL;

    printf("%d \n", new_node->data);
}