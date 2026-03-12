// Kristoffer 2026

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//create a new heap node
//parameters: n, the graph node id
//            dist, the distance between the graph node and the starting node
//return: the pointer points to the heap node
struct minHeapNode* new_min_heap_node(int n, int dist)
{
    struct minHeapNode *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
      return NULL;
    }
    new_node->graph_node_id = n;
    new_node->dist = dist;
    return new_node;
}

//create an empty binary heap
//parameters: m, the max size of the array
struct minheap *create_heap(int m)
{
    struct minheap *newHeap = malloc(sizeof(struct minheap));
    if (newHeap == NULL) {
        return NULL;
    }

    newHeap->pos = malloc(m * sizeof(int));
    if (newHeap->pos == NULL) {
      free(newHeap);
      return NULL;
    }

    newHeap->array = malloc(m * sizeof(struct minHeapNode*));
    if (newHeap->array == NULL) {
      free(newHeap->pos);
      free(newHeap);
      return NULL;
    }

    newHeap->max_size = m;
    newHeap->cur_size = 0;
    for (int i = 0; i < m; ++i) {
        newHeap->pos[i] = -1;
        newHeap->array[i] = NULL;
    }

    return newHeap;
}

//insert an element
//parameters: h, the pointer points to the heap.
//            t, the adjacent list node to be inserted into the queue
//return:  0, the heap is full.
//		   1, the element is inserted.
int insert_heap(struct minheap *h, struct minHeapNode *n)
{
    if (h->cur_size == h->max_size) {
        return 0;
    }

    int id = n->graph_node_id;
    h->cur_size++;

    int i = h->cur_size;
    h->array[i] = n;
    h->pos[id] = i;

    while (i > 1) {
        int pi = i / 2;

        if (h->array[i]->dist >= h->array[pi]->dist) {
            break;
        }

        struct minHeapNode *temp = h->array[i];
        h->array[i] = h->array[pi];
        h->array[pi] = temp;

        h->pos[h->array[i]->graph_node_id] = i;
        h->pos[h->array[pi]->graph_node_id] = pi;

        i = pi;
    }
    return 1;
}

//delete an element from the heap
//parameters: h, the pointer points to the heap.
//return: 0, the heap is empty.
//		  1, the element is deleted.
int delete_heap(struct minheap *h)
{
    if (h->cur_size == 0) {
        return 0;
    }

    struct minHeapNode *root = h->array[1];
    int rootID = root->graph_node_id;

    h->pos[rootID] = -1;


    h->array[1] = h->array[h->cur_size];
    h->cur_size--;

    if (h->cur_size > 0) {
        h->pos[h->array[1]->graph_node_id] = 1;
    }

    free(root);

    int i = 1;
    while (i * 2 <= h->cur_size) {
        int left = i * 2;
        int right = i * 2 + 1;
        int smallest = i;

        if (left <= h->cur_size && h->array[left]->dist < h->array[i]->dist) {
            smallest = left;
        }
        if (right <= h->cur_size && h->array[right]->dist < h->array[i]->dist) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }

        // swap in array
        struct minHeapNode *temp = h->array[i];
        h->array[i] = h->array[smallest];
        h->array[smallest] = temp;

        //swap in pos array
        h->pos[h->array[i]->graph_node_id] = i;
        h->pos[h->array[smallest]->graph_node_id] = smallest;

        i = smallest;
    }
    return 1;
}

//decrease the key value (i.e. the dist value of the node n to the starting node),
//  and move up the node until the heap property is satisfied
//parameter: h, the pointer points to the heap.
//           n, the id of the node
//           dist, the dist value of the node
void decreaseKey(struct minheap* h, int n, int dist)
{
    int i = h->pos[n]; // Node index
    if (i < 1) {
        return;
    }

    struct minHeapNode *node = h->array[i];
    node->dist = dist;

    while (node->dist < h->array[i/2]->dist) {
        h->array[i] = h->array[i/2];
        struct minHeapNode *temp = node;

        h->pos[h->array[i]->graph_node_id] = i;

        i = i / 2;
    }
    h->pos[node->graph_node_id] = i;
    h->array[i] = node;
}

//find the minimun value in a heap
//parameters: h, the pointer points to the heap.
//return: the printing task which has the smallest number of pages
struct minHeapNode *findmin(struct minheap *h)
{
    if (h->cur_size == 0) {
        return NULL;
    }
    return h->array[1];
}

//destroy a heap and release the space allocated to the heap
//parameters: *h, the pointer points to the heap.
void destroy_heap(struct minheap *h)
{
    for (int i = 0; i < h->max_size; ++i) {
        free(h->array[i]);
    }
    free(h->array);
    free(h->pos);
    free(h);
}

//prints the heap represented in the array
//parameters: h, the pointer points to the heap.
void display_heap(struct minheap *h)
{
    if (is_empty(h) == 1) {
        puts("Queue is empty");
    } else {
        for (int i = 1; i <= h->max_size; i++) {
            printf("ID: %d, Distance %d", h->array[i]->graph_node_id, h->array[i]->dist);
        }
    }
}

//check whether the queue is empty
//parameters: h, the pointer that points to the queue
//returns: 1 (true) or 0 (false)
int is_empty(struct minheap *h)
{
    if (h->cur_size == 0) {
        return 1;
    }

    return 0;
}
