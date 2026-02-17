// 2026 Kristoffer

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

Node *create_tree();
Node *add_node(Node *tree, int data);
void display_tree(Node *tree);
int find_largest(Node *tree, int largest);
int num_nodes(Node *tree, int n);
int height(Node *tree);
Node *create_test_tree(void);

struct Node {
  struct Node *Left;
  int data;
  struct Node *Right;
};

// Test tree
//
//                          |----------Root----------|
//                          |           10           |
//                    |-----a-----|            |-----b-----|
//                    |     7     |            |    13     |
//                |---c---|       d            e---|   |---f
//                |   3   |       9            11  |   |  16
//                g       h                        i   j
//                1       4                       12   14
// Node j = {
//   NULL, 14, NULL
// };
// Node i = {
//   NULL, 12, NULL
// };
// Node h = {
//   NULL, 4, NULL
// };
// Node g = {
//   NULL, 1, NULL
// };
// Node f = {
//   &j, 16, NULL
// };
// Node e = {
//   NULL, 11, &i
// };
// Node d = {
//   NULL, 9, NULL
// };
// Node c = {
//   &g, 3, &h
// };
// Node b = {
//   &e, 13, &f
// };
// Node a = {
//   &c, 7, &d
// };
// Node testTree = {
//   &a, 10, &b
// };
// Node *tree = &testTree;

int main(void)
{
  Node *tree = create_tree();


  int input;

  while (1) {
    int num = 0;
    int largest = INT_MIN;

    printf("\n-------------------------\n");
    printf("Binary Search Tree\n");
    printf("-------------------------\n");
    puts("1. Display tree");
    puts("2. Add node");
    puts("3. Delete node - not implemented");
    puts("4. Find largest value");
    puts("5. Find amount of nodes");
    puts("6. Find depth of tree");
    puts("20. Create a test tree");
    puts("0. Exit");
    printf("\n\nInput: ");

    scanf(" %d", &input);
    while(getchar() != '\n');

    switch (input) {
      case 0:
        return 0;
      case 1:
        if (tree == NULL) {
          puts("Tree is empty");
        }
        display_tree(tree);
        puts("");
        break;
      case 2:
        printf("Input a number: ");
        scanf(" %d", &num);
        tree = add_node(tree, num);
        break;
      case 3:
        break;
      case 4:
        printf("The largest value is %d", find_largest(tree, largest));
        break;
      case 5:
        printf("Number of nodes: %d", num_nodes(tree, num));
        break;
      case 6:
        printf("Height of tree: %d", height(tree));
        break;
      case 20:
        tree = create_test_tree();
        break;
    }
  }
  return 0;
}

Node *create_tree()
{
  Node *tree = NULL;
  return tree;
}

void display_tree(Node *tree)
{
  if (tree != NULL) {
    printf("(");
    display_tree(tree->Left);
    printf("%d", tree->data);
    display_tree(tree->Right);
    printf(")");
  }
}

Node *add_node(Node *tree, int data)
{
  if (tree == NULL) {
    tree = malloc(sizeof(*tree));
    tree->data = data;
    tree->Left = tree->Right = NULL;
    puts("Entry added successfully");

  } else {
    if (data == tree->data) {
      puts("Value already exists");
      return tree;
    } else if (data < tree->data) {
      tree->Left = add_node(tree->Left, data);
    } else {
      tree->Right = add_node(tree->Right, data);
    }
  }
  return tree;
}

int find_largest(Node *tree, int largest)
{
  if (tree->Right == NULL) {
    largest = tree->data;
  } else {
    largest = find_largest(tree->Right, largest);
  }
  return largest;
}

int num_nodes(Node *tree, int n)
{
  if (tree == NULL) {
    return 0;
  }

  n += 1;
  if (tree->Left != NULL) {
    n = num_nodes(tree->Left, n);
  }
  if (tree->Right != NULL) {
    n = num_nodes(tree->Right, n);
  }
  return n;
}

int height(Node *tree)
{
  if (tree == NULL) {
    return 0;
  }

  int leftHeight = height(tree->Left);
  int rightHeight = height(tree->Right);
  int max;

  if (leftHeight > rightHeight) {
    max = leftHeight;
  } else {
    max = rightHeight;
  }

  return 1 + max;
}

Node *create_test_tree(void)
{
  Node *tree = create_tree();
  tree = add_node(tree, 10);
  tree = add_node(tree, 7);
  tree = add_node(tree, 3);
  tree = add_node(tree, 1);
  tree = add_node(tree, 4);
  tree = add_node(tree, 9);
  tree = add_node(tree, 13);
  tree = add_node(tree, 11);
  tree = add_node(tree, 12);
  tree = add_node(tree, 16);
  tree = add_node(tree, 14);
  return tree;
}
