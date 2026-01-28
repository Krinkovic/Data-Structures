// Kristoffer 2026

#include <iterator>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "lab_lists.h"

struct node{
    char phone[11];
    char name[50];
    struct node *next;
};

// Test Phone Book
struct node entr5 = {"7692927375", "Erik", NULL};
struct node entr4 = {"8597989854", "Anders", &entr5};
struct node entr3 = {"7625257489", "Klas", &entr4};
struct node entr2 = {"7373938472", "Anna", &entr3};
struct node entr1 = {"0739332436", "Kristoffer", &entr2};

int main()
{
  struct node *start = &entr1;
  int input = -1;

  puts("");
  puts("----------------------------------");
  puts("| Welcome to the phone directory |");
  puts("----------------------------------");
  puts("");
  do {
    int option = -1;
    puts("Please pick an action (0-5):");
    puts("");
    puts("1. Display all records");
    puts("2. Insert a record");
    puts("3. Delete a record");
    puts("4. Search for a record");
    puts("5. Delete entire directory");
    puts("0. Quit");
    puts("");

    scanf( "%d", &input);

    if (input < 0 || input > 5) {
      puts("Invalid selection.");
      continue;
    }
    switch (input) {
      case 1:
        display(start);
        break;
      case 2:
        insert_record(&start);
        break;
      case 4:
        while (option != 1 || option != 2) {
          puts("1. Search by number");
          puts("2. Search by name");
          puts("0. Back");
          scanf(" %d", &option);
          if (option == 0) {
            break;
          }
          struct node *query = query_directory(start, option);
          if (query == NULL) {
            puts("Entry not found");
          } else {
            puts("Entry found:");
            printf("%s, %s", query->phone, query->name);
          }
          break;
        }
      case 0:
        return 0;
    }
  } while (input != EOF);
}

void display(struct node *start)
{
  size_t iter = 1;
  struct node *current = start;

  if (start == NULL) {
    puts("Directory is empty.");
  }
  else do {
    printf("%zu. Phone: %s, Name: %s.\n", iter, current->phone, current->name);
    current = current->next;
    iter += 1;
  } while (current->next != NULL);
  puts("");
}

int insert_record(struct node **start) {
  char nr[21];
  puts("Enter a phone number:");
  scanf(" %s", nr);

}

// option 1 or 2 for phone or name respectively
struct node *query_directory(struct node *start, int option) {
  char nr[11];
  char name[21];
  struct node *current = start;
  if (option == 1) {
    printf("Enter phone number: ");
    scanf(" %s", nr);
    do {
      if (strcmp(current->phone, nr) == 0) {
        return current;
      }
    } while (current->next != NULL);
  }
  if (option == 2) {
    printf("Enter name: ");
    scanf(" %s", name);
    do {
      if (strcmp(current->name, name) == 0) {
        return current;
      }
    } while (current->next != NULL);
  }
  return NULL;
}
