// Exercise 3 Stacks and Queues (Spring 2022)
// 3. Write a program to implement a queue using array.
//
// Implement the program by completing the functions in this supplied code.
//

#include <stddef.h>
#include <stdio.h>

#define MAX 3

//create an empty queue
int queue[MAX];
int front = -1, rear = -1;

//declare the functions for the common operations on queue
//
//insert a data element into the rear end of the queue
//parameters:
//      v: the data to be inserted into the queue
void enqueue(int v);
//delete data element from the front end of the queue
//return: the deleted data element
int dequeue(void);
//display all the elements in the queue
void display(void);


int main()
{
    //option: indicates operation request from ueser input
    //val: presents data value
    int option, val;

    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display the queue");
        printf("\n 4. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                //TODO: implement the operation
                printf("\n Enter the number to be inserted in the queue : ");
                scanf(" %d", &val);
                enqueue(val);
                break;
            case 2:
                //TODO: implement the operation
                val = dequeue();
                break;
            case 3:
                //TODO: implement the operation
                display();
                break;
        }
    }while(option != 4);

    return 0;
}

//TODO: implement the functions for the common operations on queue
//
// - [ ] enqueue
// - [ ] dequeue
// - [ ] display

void enqueue(int v)
{
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        printf("\nQueue is full.\n");
        return;
    } else {
        rear += 1;
    }
    queue[rear] = v;
}

int dequeue(void)
{
    int v;
    if (front == -1) {
        printf("\nQueue is empty.\n");
    } else if (rear == front) {
        v = queue[front];
        rear = -1;
        front = -1;
    } else {
        v = queue[front];
        front += 1;
    }
    printf("\nValue removed from queue: %d\n", v);
    return v;
}

void display(void)
{
    if (front == -1) {
        printf("\nQueue is empty.\n");
    } else {
        puts("");
        for (size_t i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
