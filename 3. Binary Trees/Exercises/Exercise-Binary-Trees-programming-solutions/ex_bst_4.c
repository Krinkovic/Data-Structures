// Exercise: Trees-1 (TDRK12 Spring 2023)
// Task 4. Write a program to find the largest element in a binary search tree. To check that it works, add the code from (1)–(3).

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
struct node *insertElement(struct node *, int);
struct node *findLargestElement(struct node *);

int main()
{
    int val;
    struct node *ptr;
    tree = create_tree(tree);
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
    ptr = findLargestElement(tree);
    if (ptr != NULL)
        printf("\n Largest element is :%d \n", ptr->data);
    else
        printf("\n Tree is empty \n");
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

struct node *insertElement(struct node *tree, int val)
{
    if (tree == NULL)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = val;
        ptr->left = ptr->right = NULL;
        tree = ptr;
    }
    else
    {
        if (val < tree->data)
            tree->left = insertElement(tree->left, val);
        else
            tree->right = insertElement(tree->right, val);
    }
    return tree;
}

struct node *findLargestElement(struct node *tree)
{
    if ((tree == NULL) || (tree->right == NULL))
        return tree;
    else
        return findLargestElement(tree->right);
}
