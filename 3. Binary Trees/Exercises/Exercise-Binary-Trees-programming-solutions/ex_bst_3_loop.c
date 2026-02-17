// Exercise: Trees-1 (TDRK12 Spring 2023)
// Task 2. Extend the program specified in (1) and (2) to perform insertion of an element into a tree. The value of an element is to be entered in a console window.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree;

void create_tree(struct node *);
void inorderTraversal(struct node *);
struct node *insertElement(struct node *, int);

int main()
{
    int val;
    create_tree(tree);
    printf("\n BINARY SEARCH TREE CREATED\n");
    printf("\n Enter the value of the new node (-1 to end): ");
    scanf("%d", &val);
    while (val != -1)
    {
        tree = insertElement(tree, val);
        printf("\n Enter the data for a new node (-1 to end) : ");
        scanf("%d", &val);
    }
    printf("\n The elements of the tree are : \n");
    inorderTraversal(tree);
    printf("\n");
    return 0;
}

void create_tree(struct node *tree)
{
    tree = NULL;
}

void inorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf(" ( ");
        inorderTraversal(tree->left);
        printf("%d", tree->data);
        inorderTraversal(tree->right);
        printf(" ) ");
    }
}

// Non-recursive implementation of insertion
struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        //tree->left = NULL;
        //tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}
