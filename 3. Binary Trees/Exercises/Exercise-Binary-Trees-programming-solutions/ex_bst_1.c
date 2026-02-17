// Exercise: Trees-1 (TDRK12 Spring 2023)
// Task 1. Write a program to create a binary search tree

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

int main()
{
    tree = create_tree(tree);
    printf("\n BINARY SEARCH TREE CREATED\n");
    return 0;
}

struct node *create_tree(struct node *tree)
{
    tree = NULL;
    return tree;
}
