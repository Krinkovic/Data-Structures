// Exercise 7 Graphs (Spring 2022)
// 1. Write a program to create and display a directed graph of N vertices using adjacency list.
// Also write the program to add and delete an edge from the graph.

#include <stdio.h>
#include <stdlib.h>


//declare a structure for node in an adjaceny list
struct adjListNode
{
    //the id of the node in a graph
    //this id is also the same as the index of the array 
    int id;
    //pointer points to the next element in the adjacency list
    struct adjListNode *next;
};

//declear a structure to present an adjacency list
struct adjList {
    //Tead is the pointer points to the first element in the list.
    //The first element in the list is a node in the graph.
    struct adjListNode* head;
};

// declare a structure to represent a graph.
// N is the max number of nodes in graph.
// A graph is an array of adjacency lists.
struct graph {
    int N;
    //an array of pointers to adjacency lists
    struct adjList* array;
};


//function prototypes

/* int: number of nodes in the graph */
/* return: a pointer to the graph
*/
struct graph* createGraph(int);

/*  struct graph: a pointer to the graph */ 
void displayGraph(struct graph*);

/* graph : a pointer to the graph */
/* source: the source node */
/* target: the target node */
void addEdge(struct graph* graph, int source, int target);

/* graph : a pointer to the graph */
/* source: the source node */
/* target: the target node */
void deleteEdge(struct graph* graph, int source, int target);


int main(void)
{
    int no_of_nodes = 4;

    struct graph* graph = createGraph(no_of_nodes);
    printf("Initialize the graph ...");
    displayGraph(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    displayGraph(graph);

    printf("Delete the edge between vertex 0 and 1...");
    deleteEdge(graph, 0, 1);
    
    displayGraph(graph);

    return 0;
}



// creates a graph of N vertices
struct graph* createGraph(int no_of_nodes)
{
    struct graph* graph = malloc(sizeof(struct graph));
    graph->N = no_of_nodes;

    // Create an N-size array of adjacency lists.
    graph->array = malloc(no_of_nodes * sizeof(struct adjList));

    //Initialize each adjacency list
    for (int i = 0; i < no_of_nodes; ++i){

        struct adjListNode* node = malloc(sizeof(struct adjListNode));
        node->id = i;
        node->next = NULL;
        graph->array[i].head = node;
    }


    return graph;
}



void addEdge(struct graph* graph, int source, int target){

    //find the adjacency list for the source node 
    struct adjListNode* adjListNode = graph->array[source].head;

    //create a new node for the target node
    struct adjListNode* newAdjListNode = malloc(sizeof(struct adjListNode));
    newAdjListNode->id = target;
    newAdjListNode->next = NULL;

    //add the target node to the end of the adjacency list of the source node
    while(adjListNode->next != NULL){
        adjListNode = adjListNode->next;
    }
    adjListNode->next = newAdjListNode;

}

void deleteEdge(struct graph* graph, int source, int target){

    if(source >= graph->N || target >= graph->N){
        printf("The source or target node doesn't exist in the graph!");
        return;
    }

    if (graph->array[source].head->next == NULL){

        printf("The edge doesn't exist in the graph!");
        return;

    }else{

        struct adjListNode* prev = graph->array[source].head;
        struct adjListNode* temp = graph->array[source].head->next;


        while( temp != NULL && temp->id != target){
            prev = temp;
            temp = temp->next;
        }

        // If target is not present in the adjacent list
        if (temp == NULL){
             printf("The edge doesn't exist in the graph!");
             return;
        }

        // Unlink the node from the adjacent list
        prev->next = temp->next;

        free(temp); // Free memory
    }
}


//print the graph
void displayGraph(struct graph* graph)
{
    for (int i = 0; i < graph->N; i++) {
        struct adjListNode* head = graph->array[i].head;

        printf("\nAdjacency list of vertex %d ", head->id);

        struct adjListNode* adj_node = head->next;
        while (adj_node != NULL) {
            printf(" -> %d ", adj_node->id);
            adj_node = adj_node->next;
        }
        printf("\n");
    }

    printf("\n");
}
