#include <stdio.h>

#define MAX_ARR 200*200;

typedef struct {
    
    int arr[MAX_ARR]
    int Col;
    int Lin;
    
} Cadeiras;

void swap_whole(Cadeiras *cadei, int index1, int index2);
void swap(int *el1, int *el2);

int main()
{

    return 0;
}

void sort_arr(Cadeiras *cadei)
{
    


}

int sort_line(Cadeiras *cadei)
{
    int times = 0;

    int C = cadei->Col;
    int L = cadei->Lin;

    int size = L*C;
    
    int i;
    for(i=0; i < size; i+C){
		
	if(cadei.arr[i] > cadei.arr[(i+C)]){
	    
	    swap_line(cadei, i, i+4);
	    times++;
	}

    }
}

void swap_line(Cadeiras *cadei, int index1, int index2)
{

    int C = cadei->Col;
    
    int *el1, *el2;
    
    int i;
    for(i=0; i<C; i++){
		
	el1 = &cadei.arr[(index1 + i)];
	el2 = &cadei.arr[(index2 + i)];

	swap(el1, el2);
    }
}

void swap(int *el1, int *el2)
{
    int temp;

    temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}
