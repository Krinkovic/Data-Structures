//Exercise: Heaps  (Spring 2022)
// Write a program to implement a max binary heap queue.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//incomplete declaration to the structure
struct maxheap{
    //pointer to an integer array
    int *array;
    //the array size
    int max_size;
    //the last position of the array
    int cur_pos;
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
struct maxheap *create_heap() {
    //allocate memory for the heap
    struct maxheap *h;
    h = malloc(sizeof(struct maxheap));

    //initialize the heap
    h->max_size = 20;
    h->cur_pos = 0;

    //allocate memory for the array
    h->array =  malloc(sizeof(int)*(h->max_size+1));

    return h;
}

void destroy_heap(struct maxheap *h) {
    //release the memory allocated to the array
    free(h->array);
    //release the memory allocated to the heap
    free(h);
}

void print_heap(struct maxheap *h) {
    //print the heap
    if (h->cur_pos < 1){
        printf("Heap is empty!\n");
        return;
    }

    //print the heap as a sequence of values in the array
    for (int i = 1; i < h->cur_pos + 1; i++) {
        printf("%d  ", h->array[i]);
    }

    //if print the heap in the tree structure
    //the root is at level 0
    //the level of the node is determined by the position of the node in the array
    //use a recursive function to print the tree structure
    
}

int findmax(struct maxheap *h) {
    //find the maximum value in the heap
    if (h->cur_pos <1) {
        printf("Heap is empty!\n");
        //exit the program
        //abort();
        return -1; // -1 indicates an error
    }
    // min is always in first position
    return h->array[1];
}


void insert(struct maxheap *h, int key) {
    //insert an element to the heap
    // make sure there is space
    if (h->cur_pos == h->max_size)
        printf("The heap is full. Cannot insert");

    else{

        h->cur_pos++;
        // step 1: add at the bottom, as a leaf at leftmost position
        h->array[h->cur_pos] = key;
        // step 2: checking whether it breaks heap property
        // if yes, fix its position by moving up
        moveup(h, h->cur_pos);
    }

    return;
}

//implement moveup using a recursive function
void moveup(struct maxheap *h, int pos) {
    //move up the node at pos to its correct position
    //if the parent of the node is smaller than the node, swap the node with its parent
    //repeat the process until the node is at the root or the parent of the node is larger than the node
    //pos: the position of the node to be moved up
    //h: the pointer to the heap
    int parent;
    //if the node is at the root, return
    if (pos == 1)
        return;
    //find the parent of the node
    parent = pos/2;
    //if the parent is smaller than the node, swap the node with its parent
    if (h->array[parent] < h->array[pos]){
        swap(h, parent, pos);
        //move up the parent
        moveup(h, parent);
    }
}

//another way to implement moveup, which uses a while loop.
//void moveup(struct maxheap *h){
//    int k = h->cur_pos;
    //move up until the heap property satisfies
    //  or the node becomes the root node. 
//    while (k>1 && h->array[k] > h->array[k/2]) {
//        swap(h, k/2, k);
//        k = k/2;
//    }
//}

//swap the values of the nodes at position i and j
void swap(struct maxheap *h, int i, int j) {
    //swap the values of the nodes at position i and j
    int temp;
    temp = h->array[i];
    h->array[i] = h->array[j];
    h->array[j] = temp;
}


void delete(struct maxheap *h) {
    //delete the maximum value in the heap
    //replace the root with the last element in the heap
    //move down the new root to its correct position
    if (h->cur_pos < 1){
        printf("Heap is empty!\n");
        return;
    }

    //Step 1: replace the root with the last element in the heap
    h->array[1] = h->array[h->cur_pos];

    //not necessary to store the root value in the last position
    //since anyhow the last position will be decreased
    //decrease the size of the heap
    h->cur_pos--;
    //Step 2: move down the new root to its correct position
    movedown(h, 1);
}


void movedown(struct maxheap *h, int k) {
    //i represents the left child of the node at position k
    //j represents the right child of the node at position k
    int i = 2*k, j=i+1;

    //move down until the node does not hae child
    while(i <= h->cur_pos ){

        //if the right child exists
        //   and the right child is greater than the left child
        //   and the node is smaller than the right child
        if(j <= h->cur_pos && h->array[i] <= h->array[j] && h->array[k] <= h->array[j]){
            swap(h, j, k);
            k = j;
        }
        //if the node is smaller than the left child
        else if(h->array[k] <= h->array[i]){
            swap(h, i, k);
            k = i;
        }
        else{
            //stop the loop since the max heap property is satisfied
            break;
        }

        //update i and j
        i = 2*k;
        j = i+1;
    }
}
