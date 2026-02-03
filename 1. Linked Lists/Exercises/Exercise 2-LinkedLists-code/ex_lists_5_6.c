#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *);

/*
    The function to display the data in the linked list.
    parameters:
        - start pointer points the first node in the linked list.
*/
struct node *display(struct node *);
/*
  delete data in the beginning of the linked list.
*/
struct node *delete_beg(struct node *);

/*
  delete data at the end of the linked list.
*/
struct node *delete_end(struct node *);


int main()
{
    
    start = create_ll(start);
    display(start);

    //start = delete_beg(start);
    start = delete_end(start);
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


struct node *delete_beg(struct node *start)
{

    printf("Deleting the first node...\n");

    if(start == NULL)
    {
        printf("UNDERFLOW!\n");
        return start;
    }

    struct node *ptr;
    ptr = start;

    start = start->next;

    free(ptr);

    return start;
}

struct node *delete_end(struct node *start)
{

    printf("Deleting the last node...\n");

    if(start == NULL)
    {
        printf("UNDERFLOW!\n");
        return start;

    }

    //only one node in the list
    if(start->next == NULL){
        free(start);   
        start = NULL;     
        return start;
    }

    
    struct node *ptr, *preptr;
    ptr = start;
    preptr = ptr;

    while(ptr->next != NULL)
    {
            preptr = ptr;
            ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    return start;
}
