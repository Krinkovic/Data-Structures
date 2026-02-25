// Exercise: Trees-2 (TDRK12 Spring 2022)
// Task 1. Write a program to create manually (node by node) the B-tree from slide 8 (fig. 11.4 in the textbook).

#include <stdio.h>
#include <stdlib.h>

// MAX is the order of the B-tree
#define MAX 4

struct node
{
    struct node *children[MAX]; // M sub-trees
    int keys[MAX - 1]; // M-1 keys
    int key_count; // number of keys, number of children is key_count+1
};

struct node *root;

// Creates a B-tree node with the given keys, number of keys and pointers to children
struct node *createNode(int keys[], int count, struct node *children[])
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key_count = count;
    for (size_t i = 0; i < count; i++)
    {
        newNode->keys[i] = keys[i];
        newNode->children[i] = children[i];
    }
    newNode->children[count] = children[count];
    return newNode;
}

int main()
{
    // Max amount of children for all nodes is 4
    struct node *leaf_children[4] = {NULL, NULL, NULL, NULL};

    // Create the left sub-tree
    int leaf1_keys[2] = {18, 27};
    struct node *leaf1 = createNode(leaf1_keys, 2, leaf_children);

    int leaf2_keys[2] = {30, 31};
    struct node *leaf2 = createNode(leaf2_keys, 2, leaf_children);

    int leaf3_keys[2] = {36, 39};
    struct node *leaf3 = createNode(leaf3_keys, 2, leaf_children);

    int inter1_keys[2] = {29, 32};
    struct node *inter1_children[3] = {leaf1, leaf2, leaf3};
    struct node *inter1 = createNode(inter1_keys, 2, inter1_children);

    // Create the right sub-tree
    int leaf4_keys[2] = {46, 47};
    struct node *leaf4 = createNode(leaf4_keys, 2, leaf_children);

    int leaf5_keys[3] = {54, 59, 61};
    struct node *leaf5 = createNode(leaf5_keys, 3, leaf_children);

    int leaf6_keys[2] = {67, 72};
    struct node *leaf6 = createNode(leaf6_keys, 2, leaf_children);

    int inter2_keys[2] = {49, 63};
    struct node *inter2_children[3] = {leaf4, leaf5, leaf6};
    struct node *inter2 = createNode(inter2_keys, 2, inter2_children);

    // Create the root
    int root_keys[1] = {45};
    struct node *root_children[2] = {inter1, inter2};
    root = createNode(root_keys, 1, root_children);
}
