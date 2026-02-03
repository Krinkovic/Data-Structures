// Kristoffer 2026

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lab_lists.h"

struct node{
    char phone[11];
    char name[50];
    struct node *next;
};

void display(struct node *start);
int insert_record(struct node **start);
int delete_record(struct node **start);
struct node *query_directory(struct node *start, int option);
void delete_directory(struct node **start);

int main()
{
  struct node *start = NULL;
  int input = -1;

  puts("");
  puts("----------------------------------");
  puts("| Welcome to the phone directory |");
  puts("----------------------------------");
  puts("");
  do {
    int option = -1;
    int insert = -1;
    struct node *query;
    puts("Please pick an action (0-5):");
    puts("");
    puts("1. Display all records");
    puts("2. Insert a record");
    puts("3. Delete a record");
    puts("4. Search for a record");
    puts("5. Delete entire directory");
    puts("0. Quit");
    puts("");

    printf("Input: ");
    if (scanf( "%d", &input) != 1 || input < 0 || input > 5) {
      while(getchar() != '\n');
      puts("Invalid selection.");
      puts("----------------------------------");
      continue;
    }
    puts("");

    switch (input) {
      case 1:
        display(start);
        puts("----------------------------------");
        puts("");
        break;
      case 2:
        insert = insert_record(&start);
        if (insert == -1) {
          puts("Entry already exists.");
        puts("----------------------------------");
        puts("");
        } else if (insert == 0){
          puts("Entry added.");
        puts("----------------------------------");
        puts("");
        }
        break;
      case 3:
        delete_record(&start);
        display(start);
        puts("----------------------------------");
        puts("");
        break;
      case 4:
        puts("1. Search by number");
        puts("2. Search by name");
        scanf(" %d", &option);
        query = query_directory(start, option);

        if (query == NULL) {
          puts("Entry not found");
        } else {
          printf("Entry found: ");
          printf("%s, %s\n", query->phone, query->name);
        }
        puts("----------------------------------");
        puts("");
        break;
      case 5:
        delete_directory(&start);
        break;
      case 0:
        if (start != NULL) {
          delete_directory(&start);
        }
        puts("Goodbye");
        return 0;
    }
  } while (input != 0);
  delete_directory(&start);
  return 0;
}

void display(struct node *start)
{
  size_t iter = 1;
  struct node *current = start;

  if (start == NULL) {
    puts("Directory is empty.");
  }

  else while (current != NULL) {
    printf("%zu. Phone: %s, Name: %s.\n", iter, current->phone, current->name);
    current = current->next;
    iter += 1;
  };
  puts("");
}

int insert_record(struct node **start)
{
  char nr[11];
  struct node *current = *start;
  puts("Enter a phone number:");
  scanf(" %s", nr);
  while (current != NULL) {
    if (strcmp(current->phone, nr) == 0) {
      return -1;
    }
    current = current->next;
  }

  struct node *new_node = malloc(sizeof(struct node));
  strcpy(new_node->phone, nr);
  puts("Enter name:");
  scanf(" %s", new_node->name);
  new_node->next = *start;
  *start = new_node;
  return 0;
}

int delete_record(struct node **start) {
  struct node *current = *start;
  struct node *prev = NULL;
  char nr[11];
  char name[50];
  int option;

  if (start == NULL) {
    puts("Directory is empty.");
    puts("----------------------------------");
    puts("");
    return -1;
  }

  puts("1. Search by number");
  puts("2. Search by name");
  printf("Input: ");
  scanf(" %d", &option);
  puts("");

  if (option == 1) {
    printf("Enter phone number: ");
    scanf(" %s", nr);
    puts("");
    while (current != NULL) {
      if (strcmp(current->phone, nr) == 0) {
        if (prev == NULL) {
          *start = current->next;
        } else {
          prev->next = current ->next;
        }
        free(current);
        puts("Entry deleted.");
        puts("");
        return 0;
      }
      prev = current;
      current = current->next;
    }
  }
  if (option == 2) {
    printf("Enter name: ");
    scanf(" %s", name);
    puts("");
    while (current != NULL) {
      if (strcmp(current->name, name) == 0) {
        if (prev == NULL) {
          *start = current->next;
        } else {
          prev->next = current ->next;
        }
        free(current);
        puts("Entry deleted.");
        puts("");
        return 0;
      }
      prev = current;
      current = current->next;
    }
  }
  return -1;
}

// option 1 or 2 for phone or name respectively
struct node *query_directory(struct node *start, int option)
{
  char nr[11];
  char name[21];
  struct node *current = start;
  if (option == 1) {
    printf("Enter phone number: ");
    printf("Input: ");
    scanf(" %s", nr);
    puts("");
    do {
      if (strcmp(current->phone, nr) == 0) {
        return current;
      }
      current = current->next;
    } while (current != NULL);
  }
  if (option == 2) {
    printf("Enter name: ");
    printf("Input: ");
    scanf(" %s", name);
    puts("");
    do {
      if (strcmp(current->name, name) == 0) {
        return current;
      }
      current = current->next;
    } while (current != NULL);
  }
  return NULL;
}

void delete_directory(struct node **start)
{
  struct node *current = *start;
  struct node *prev = NULL;
  while (current != NULL) {
    prev = current;
    current = current->next;
    free(prev);
  }
  *start = NULL;
  puts("Records cleared.");
  puts("----------------------------------");
  puts("");
}
