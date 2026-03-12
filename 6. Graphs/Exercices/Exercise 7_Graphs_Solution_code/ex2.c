// Exercise 7 Graphs (Spring 2022)
//3. Write a program to implement the breadth-first search algorithm.
#include <stdio.h>
#define MAX 5


//create an empty queue
int queue[MAX];
int front = -1, rear = -1;
//declare the functions for the common queue operations
void enqueue(int e);
//delete data element from the front end of the queue
//return: the data element deleted
int dequeue();
void display_queue();
//check whether the queue is empty
//return: 1, true; 0, false
int is_queue_empty();
//parameters: adj, the adjancent matrix
//            status, the status array
//            start, the starting node
void breadth_first_search(int adj[][MAX], int start);



int main()
{

    /*the adjacent matrix
    // the undirected graph
    int adj[MAX][MAX] =  {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}
    };*/


    //the directed graph
    int adj[MAX][MAX] =  {
            {0, 1, 0, 1, 0},
            {0, 0, 0, 1, 0},
            {0, 1, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0}
    };

    /* Or build the graph from user inputs
    int i, j;
    printf("\n Enter the adjacency matrix: ");
    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);
    */

    breadth_first_search(adj,0);
    return 0;
}



//parameters: adj, the adjancent matrix
//            start, the starting node
void breadth_first_search(int adj[][MAX], int start)
{
    //status, 1:unvisited; 2:waiting; 3: visited.
    int status[MAX] = {[0 ... MAX-1]=1};

    enqueue(start);
    status[start] = 2;

    int cur;
    //the queue is not empty
    while(is_queue_empty(queue) != 1)
    {

        cur = dequeue();
        status[cur] = 3;
        //print the character from its ascii code
        printf("%c \t", cur + 65);

        //for each of the neighbors of the node
        for(int i = 0; i < MAX; i++)
        {
            if(adj[cur][i] == 1 && status[i] == 1)
            {
                enqueue(i);
                status[i] = 2;
            }
        }
    }

    printf("\n");
}

//the operation is also called enqueue
void enqueue(int element)
{

    if(rear == MAX-1)
        printf("\n OVERFLOW");
    //insert the new data element and update the variables FRONT and REAR
    else {
        //when the queue is empty
        if(front == -1 && rear == -1)
            front = rear = 0;
        else
            rear++;
        queue[rear] = element;

    }
}

//the operation is also called dequeue
int dequeue()
{
    int val;

    if(front == -1 || front>rear)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    //delete the data element and update the variables FRONT and REAR
    else
    {
        val = queue[front];
        front++;
        //val is the only element in the queue
        if(front > rear)
            front = rear = -1;
        return val;
    }
}

void display_queue()
{
    if(front == -1 || front > rear)
        printf("\n QUEUE IS EMPTY");
    else
    {
        printf("\n");
        //iterate the array and print the data
        for(int i = front; i <= rear; i++)
            printf("\t %d", queue[i]);
    }
}


int is_queue_empty()
{
    if(front == -1 || front > rear)
        return 1;
    else return 0;
}
