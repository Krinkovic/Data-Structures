// Kristoffer 2026

//Exercise: Heaps  (Spring 2022)
// Write a program to implement a max binary heap queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//incomplete declaration to the structure
struct maxheap {
    int *array;
    int max; // Max size of array
    int pos; // current position
};

//create an empty binary heap
struct maxheap *create_heap();
//insert an element
//parameters: h, the pointer points to the heap.
//            key, the element to be inserted
void insert(struct maxheap *h, int key);
//delete an element
//parameters: h, the pointer points to the heap.
void delete(struct maxheap *h);
//find the maximun value in a heap
//parameters: h, the pointer points to the heap.
int findmax(struct maxheap *h);
//destroy a heap and release the space allocated to the heap
//parameters: h, the pointer points to the heap.
void destroy_heap(struct maxheap *h);
//prints the heap in the array
//parameters: h, the pointer points to the heap.
void print_heap(struct maxheap *h);

void moveup(struct maxheap *h, int pos);
void movedown(struct maxheap *h, int k);
void swap(struct maxheap *h, int i, int j);



int main(void) {

    //option: operation request from ueser input
    //val: data value
    int val, option;

    struct maxheap *heap = create_heap();

    do
    {
        printf("\n\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. FIND MAX VALUE");
        printf("\n 4. DESTROY");
        printf("\n 5. DISPLAY");
        printf("\n 6. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter the number to be added to the heap: ");
                scanf("%d", &val);
                insert(heap,val);
                break;

            case 2:
                delete(heap);
                break;

            case 3:
                printf("The max value in the heap is %d. \n", findmax(heap));
                break;

            case 4:
                destroy_heap(heap);
                //exit when the heap is destroyed.
                return 0;

            case 5:
                print_heap(heap);
                break;
        }
    //while not choose to exit
    }while(option != 6);

    return 0;
}


//TODO: implement the functions

//create an empty binary heap
struct maxheap *create_heap()
{
    struct maxheap *heap = malloc(sizeof(*heap));
    heap->max = MAX;
    heap->pos = 0;
    heap->array = malloc(sizeof(int) * heap->max + 1);
    return heap;
}

//insert an element
//parameters: h, the pointer points to the heap.
//            key, the element to be inserted
void insert(struct maxheap *h, int key)
{
    if (h->pos == h->array[h->max]) {
        puts("Heap is full");
    } else {
        h->pos += 1;
        h->array[h->pos] = key;
        moveup(h, h->pos);
    }
}

//delete an element
//parameters: h, the pointer points to the heap.
void delete(struct maxheap *h)
{
    if (h->pos == h->array[0]) {
        puts("Heap is empty.");
    } else {

    }
}
//find the maximun value in a heap
//parameters: h, the pointer points to the heap.
int findmax(struct maxheap *h)
{
    if (h->pos == 0) {
        puts("Heap is empty");
        return -1;
    }
    return h->array[1];
}
//destroy a heap and release the space allocated to the heap
//parameters: h, the pointer points to the heap.
void destroy_heap(struct maxheap *h)
{
    free(h);
    puts("Heap destroyed");
}
//prints the heap in the array
//parameters: h, the pointer points to the heap.
void print_heap(struct maxheap *h)
{
    if (h->pos == 0) {
        puts("Heap is empty");
    } else {
        int i;
        for (i = 1; i < MAX; i++) {
            printf("%d, ", h->array[i]);
        }
        puts("");
    }
}

void moveup(struct maxheap *h, int pos)
{
    int val = h->array[pos];
    int parent = h->array[h->pos / 2];
    if (parent > val) {
        h->array[h->pos / 2] = val;
        h->array[h->pos] = parent;
        moveup(h, parent);
    }
}

void movedown(struct maxheap *h, int k);

void swap(struct maxheap *h, int i, int j);
