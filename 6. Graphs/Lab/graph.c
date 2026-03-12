// Kristoffer 2026

// #include <regex>
#include <stdlib.h>
#include "graph.h"

//create a graph
//parameters: int, the number of nodes in the graph
//return: the pointer points to the graph
struct graph* createGraph(int n)
{
    struct graph *graph = malloc(sizeof(*graph));
    if (graph == NULL) {
      return NULL;
    }
    graph->N = n;
    graph->array = malloc(n * sizeof(struct adjList));
    if (graph->array == NULL) {
      return NULL;
    }

    for (int i = 0; i < n; ++i) {
        struct adjListNode *node = malloc(sizeof(*node));
        node->graph_node_id = i;
        node->weight = 0;
        node->next = NULL;
        graph->array[i].head = node;
    }

    return graph;
}

//display an edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            cities, the cities referenced by the node id in the graph
void displayGraph(struct graph* graph, char **cities)
{
    for (int i = 0 ; i < graph->N; ++i) {
        struct adjListNode *city = graph->array[i].head;
        printf("%s\n", cities[i]);
        while (city != NULL) {
            if (city->weight != 0) {
                printf("    %s %d\n", cities[city->graph_node_id], city->weight);
            }
            city = city->next;
        }
    }
}

//add an edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target nonde
//            weight, the weight of the edge
void addEdge(struct graph* graph, int source, int target, int weight)
{
    struct adjListNode *node = graph->array[source].head;
    struct adjListNode *newNode = malloc(sizeof(*newNode));
    newNode->graph_node_id = target;
    newNode->weight = weight;
    newNode->next = NULL;

    while (node->next != NULL) {
        node = node->next;
    }
    node->next = newNode;
}

//delete the edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target node
// void deleteEdge(struct graph* graph, int source, int target)
// {

// }
