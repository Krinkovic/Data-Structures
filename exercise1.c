// Kristoffer 2026

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "lab_lists.h"

int main()
{
  struct node start = {-1, {"", ""}, NULL};

  // Test directory
  struct node start = {62855, {"Forsberg", "Kristoffer"}, NULL};

  char input[] = "";
  while (scanf( "%s", input) != EOF) {
    puts("Welcome to the phone directory. Please pick an action (1-5):");
    puts("1. Display all records");
    puts("2. Insert a record");
    puts("3. Delete a record");
    puts("4. Search for a record");
    puts("5. Delete entire directory");
  }
}

void display(struct node *start)
{
  size_t iteration = 0;
  struct node *current = start;

  if (current->phone == -1) {
    puts("Directory is empty.");
  }
  else do {
    printf("%zul. Name: %s, %s. Phone: %d\n", iteration, current->name.last, current->name.first, current->phone);
    current = current->next;
  } while (current->next != NULL);
}
