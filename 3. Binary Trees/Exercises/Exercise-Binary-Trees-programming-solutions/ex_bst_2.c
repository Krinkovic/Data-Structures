// Exercise: Trees-1 (TDRK12 Spring 2023)
// Task 2. Extend the program specified in (1) to display the created binary search tree using in-order traversal in a console window.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree;

struct node *create_tree(struct node *);
void inorderTraversal(struct node *);

int main()
{
    tree = create_tree(tree);
    printf("\n BINARY SEARCH TREE CREATED\n");
    printf("\n The elements of the empty tree are : \n");
    inorderTraversal(tree);
    // Create an element to test
    tree = (struct node *)malloc(sizeof(struct node));
    tree->data = 5;
    tree->left = tree->right = NULL;
    printf("\n The elements of the tree are : \n");
    inorderTraversal(tree);
    return 0;
}

struct node *create_tree(struct node *tree)
{
    tree = NULL;
    return tree;
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
