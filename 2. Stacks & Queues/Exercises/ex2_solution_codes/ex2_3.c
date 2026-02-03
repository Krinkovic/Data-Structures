// Exercise 3 Stacks and Queues (Spring 2022)
// 4. Write a program to implement a circular queue.
//
// Implement the program by completing the functions in this supplied code. 
//

#include <stdio.h>

#define MAX 10

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
                printf("\n Enter the number to be inserted in the queue : ");
                scanf(" %d", &val);
                enqueue(val);
                break;
            case 2:               
                val = dequeue();
                break;
            case 3:              
                display();
                break;
        }
    }while(option != 4);

    return 0;
}


void enqueue(int num){

    if((front ==0 && rear == MAX-1) || rear == front -1)
        printf("\n OVERFLOW!");
   
    //when the queue is empty
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = num;
    }
    //when rear reaches the last index of the array
    //but the queue is not full.
    else if(rear==MAX-1 && front !=0){
        rear = 0;
        queue[rear] = num;
    }
    //others
    else{
        rear++;
        queue[rear] = num;
    }
}

int dequeue(){

    int val;

    if(front == -1 && rear == -1){
        printf("\n UNDERFLOW");
        return -1;
    }else{

        val = queue[front];

        //if val is the last element
        if(front == rear)
            front = rear = -1;
        else{
            //when front reaches the last index of the array
            if(front==MAX-1)
                front = 0;
            //others
            else
                front++;
        }

        return val;
    }
}

void display()
{
    if(front == -1 && rear == -1)
        printf("\n QUEUE IS EMPTY");
    else
    {
        printf("\n");
        //iterate the array and print the data
        if(rear >= front){
            for(int i = front; i<=rear; i++)
               printf("\t %d", queue[i]); 

        }else{

            for(int i = front; i <= MAX-1; i++)
                printf("\t %d", queue[i]);

            for(int i =0; i<=rear; i++)
                printf("\t %d", queue[i]);
        }
       
    }
}