// Exercise 7 Graphs (Spring 2022)
// 3. Write a program to implement Floyd-Warshall algorithm
#include <stdio.h>

//the number of vertices in graph
#define N 4
//the infinity value
#define INFINITY 9999

void display(int mat[N][N]);

int main()
{
    //an adjacency matrix of the graph
    //represents the example 13.13 in the course book.
    int adj[N][N] = {
            {0, 3, 3, 0},
            {0, 0, 0, 1},
            {0, 3, 0, 0},
            {2, 0, 5, 0}
    };

    display(adj);

    //TO DO: implement Floyd-Warshall algorithm
      /* code */



    return 0;
}


void display(int mat[N][N])
{
    for(int i=0;i<N;i++){
        printf("\n");
        for(int j=0;j<N;j++)
            printf("%d\t", mat[i][j]);
    }

    printf("\n");
}
