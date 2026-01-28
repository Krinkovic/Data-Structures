// Exercise: Linked Lists (TDRK12 Spring 2025)
// Task 4. Write a program to perform insertion after a given node in a linked list. 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

/*
  create a linked list
*/
struct node *create_ll(struct node *);

struct node *display(struct node *);
/*
  insert data after a given node.
*/
struct node *insert_after(struct node *);


int main()
{
    
    start = create_ll(start);
    display(start);

    start = insert_after(start);
    display(start);

    return 0;
}


struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    start = NULL;

    int num;
    printf("\nCreating a list.");
    //We consider positive integers for the data in the linked list.
    //-1 : finish entering the data.
    printf("\nEnter the data for a new node (-1 to end) : ");

    scanf("%d", &num);

    while(num != -1)
    {
        new_node = malloc(sizeof(struct node));

        //we are inserting new node in the end of the linked list,
        //so the new node will be the last node of the linked list.
        new_node->data = num;
        //the next points to NULL in the last node.
        new_node->next = NULL;

        //the linked list is empty.
        if(start == NULL){

            start = new_node;
        //the linked list is not empty.
        }else{

            ptr = start;

            while(ptr->next !=NULL){
                ptr = ptr->next;
            }

            ptr->next = new_node;
        }

        printf("\n Enter the data for a new node (-1 to end) : ");
        scanf("%d", &num);
    }

    printf("\n The linked list is created.\n");
    return start;
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


struct node *insert_beg(struct node *start)
{
    struct node *new_node;

    int num;
    printf("\n Enter the data to insert at the beginning : ");
    scanf("%d", &num);

    new_node = malloc(sizeof(struct node));

    new_node->data = num;
    new_node->next = start;
    start = new_node;

    return start;
}


struct node *insert_after(struct node *start){

    if(start == NULL){
        start = insert_beg(start);
        return start;

    }else{
    
        int num, val;
        printf("\n Enter the data for a new node : ");
        scanf("%d", &num);
        
        printf("\n Enter the value after which the data has to be inserted : ");
        scanf("%d", &val);

        struct node *new_node, *ptr, *preptr;

        //create the new node
        new_node = malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;

        ptr =start;
        preptr = start;
        
        while(preptr->data != val){

            preptr = ptr;
            ptr = ptr->next;
        }
   
        //when insert data after the first node in the linked list.
        if(preptr == ptr)        
            ptr = ptr->next;
                        
        preptr->next = new_node;
        new_node->next = ptr;  

        return start;
    }     
}


