// Kristoffer 2026

//Exercise: Heaps  (Spring 2022)
// Write a program to implement a max binary heap queue.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <threads.h>

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
    heap->max = 30;
    heap->pos = 0;
    heap->array = malloc(sizeof(int) * heap->max + 1);
    return heap;
}

//insert an element
//parameters: h, the pointer points to the heap.
//            key, the element to be inserted
void insert(struct maxheap *h, int key)
{

}

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
