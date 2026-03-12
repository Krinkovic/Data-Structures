// Exercise 7 Graphs (Spring 2022)
// 5. Write a program to implement Floyd-Warshall algorithm
#include <stdio.h>

#define N 4
#define INFINITY 9999

void display(int mat[N][N]);
void mul(int mat[N][N]);

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

    //initialize the reachability matrix
    int D[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            if(adj[i][j] == 0)
                D[i][j] = INFINITY;
            else
                D[i][j] = adj[i][j];
    }

    //the shortest path exists between two vertices using vertices 1,2,..,k
    //k is from vertice 0 to N-1
    for(int k=0; k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
           for(int j=0;j<N;j++)
                if(D[i][j] <= D[i][k] + D[k][j])
                    D[i][j] = D[i][j];
                else
                    D[i][j] = D[i][k] + D[k][j];
        }
    }

    printf("\n The calculated matrix is :");
    display (D);

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
