// 2026 Kristoffer

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lab_multiway_trees.h"

#define MAX 4

struct node
{
  struct node *children[MAX];
  int keys[MAX-1];
  int keyCount;
};

struct node *createNode(int keys[], int count, struct node *children[])
{
  struct node *newNode;
  newNode = malloc(sizeof(*newNode));
  newNode->keyCount = count;
  for (size_t i = 0; i < count; i++) {
    newNode->keys[i] = keys[i];
    newNode->children[i] = children[i];
  }
  newNode->children[count] = children[count];
  return newNode;
}

  /*
  node = {
    keys = {54, 59, 61}
    keysCount = 3
    children = {leaf1, leaf2, leaf3, leaf4}
  }
  inOrder(tree)
    while tree is not NULL
      for (i = 0; i < tree->keysCount; i++)
        inOrder(tree->children[i]);
        print tree->keys[i];
      inOrder(tree->children[tree->keysCount]);
  */
void traverse(struct node *tree, int level)
{
  if (tree != NULL) {
    for (size_t i = 0; i < tree->keyCount; i ++) {
      traverse(tree->children[i], level + 1);
      for (size_t i = 0; i < level; i++) {
        printf("    ");
      }
      printf("%d\n", tree->keys[i]);
    }
    traverse(tree->children[tree->keyCount], level + 1);
  }
}

struct node *search(struct node *tree, int val)
{
  if (tree == NULL) {
    return NULL;
  }

}

int main(void)
{
  struct node *root;

  struct node *leafChildren[4] = {NULL, NULL, NULL, NULL};
  int leaf1Keys[2] = {18, 27};
  struct node *leaf1 = createNode(leaf1Keys, 2, leafChildren);
  int leaf2Keys[2] = {30, 31};
  struct node *leaf2 = createNode(leaf2Keys, 2, leafChildren);
  int leaf3Keys[2] = {36, 39};
  struct node *leaf3 = createNode(leaf3Keys, 2, leafChildren);

  int leaf4Keys[2] = {46, 47};
  struct node *leaf4 = createNode(leaf4Keys, 2, leafChildren);
  int leaf5Keys[3] = {54, 59, 61};
  struct node *leaf5 = createNode(leaf5Keys, 3, leafChildren);
  int leaf6Keys[2] = {67, 72};
  struct node *leaf6 = createNode(leaf6Keys, 2, leafChildren);

  int internalKeys1[2] = {29, 32};
  struct node *internalChildren1[3] = {leaf1, leaf2, leaf3};
  struct node *internal1 = createNode(internalKeys1, 2, internalChildren1);
  int internalKeys2[2] = {49, 63};
  struct node *internalChildren2[3] = {leaf4, leaf5, leaf6};
  struct node *internal2 = createNode(internalKeys2, 2, internalChildren2);

  int rootKeys[1] = {45};
  struct node *rootChildren[2] = {internal1, internal2};
  root = createNode(rootKeys, 1, rootChildren);

  traverse(root, 1);
}
