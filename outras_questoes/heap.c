#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100

typedef struct {
    int size;
    int data[MAX_HEAP];
} heap;

void print_heap(heap *arr);
void makeheap(heap *heap);

void swap(int *one, int *two);
void max_heapify(heap *heap);
void heapify(heap *heap, int parent);
void heapsort(heap *arr);

int main()
{
    heap merda;

    makeheap(&merda);

    heapsort(&merda);

    printf("Resultado Final: %d ", merda.data[1]);
    print_heap(&merda);
    printf("\n");

    return 0;
}

void makeheap(heap *heap)
{
    int n, i = 0;

    while(scanf("%d", &n) != EOF) {
	i++;
	heap->data[i] = n;
    }    

    heap->size = i;
}

void heapsort(heap *heap)
{
    int *len = &heap->size; 
    int original_len = *len;

    printf("Estado inicial: %d ", heap->data[1]);
    print_heap(heap);
    printf("\n");

    max_heapify(heap);


    printf("Estado Atual da Heap: %d ", heap->data[1]);
    print_heap(heap);
    printf("\n");
    printf("Maior elemento neste passo: %d\n", heap->data[1]);


    while(*len >= 2){

	swap(&heap->data[1], &heap->data[(*len)]);

	(*len)--;
	
	max_heapify(heap);

	printf("Estado Atual da Heap: %d", heap->data[1]);
	if((*len) > 1){
	    printf(" ");
	    print_heap(heap);
	    printf("\n");
	    printf("Maior elemento neste passo: %d", heap->data[1]);
	} 
	printf("\n");
	    
    }

    heap->size = original_len;
}

void max_heapify(heap *heap)
{
    int i;
    int len = heap->size; 
    for(i=1; i<=len; i++)
	  heapify(heap, i);
}

void heapify(heap *heap, int parent)
{
    int len = heap->size; 

    int large_index = parent;
    
    int left_n  = parent << 1;
    int right_n = left_n + 1;

    if(left_n <= len && heap->data[parent] < heap->data[left_n]){

	large_index = left_n;    
    }

    if(right_n <= len &&  heap->data[large_index] < heap->data[right_n]){

	large_index = right_n;    
    }

    if(heap->data[large_index] != heap->data[parent]){

	swap(&heap->data[parent], &heap->data[large_index]);
	//max_heapify(heap, large_index);
    }
	
}

void swap(int *one, int *two)
{
    int temp;
    temp = *two;
    *two = *one;
    *one = temp;
}

void print_heap(heap *heap)
{

    int len = heap->size;

    int i = 2;

    while(i<len){
	printf("| %d ", heap->data[i]);
	i++;
    }    
    printf("| %d", heap->data[(len)]);

}
