#include <stdio.h>

void make_arr(int count, int max, int *arr);

void tocas(int count, int *arr, int size, int index,
	   int var1, int var, int num_tocas);

int main()
{
    int size;
    scanf("%d", &size);

    int arr[size]; 
    size--;
    
    make_arr(0, size, arr);

    tocas(0, arr, size, 0, 0, 0, 0);

    return 0;

}

void tocas(int count, int *arr, int size, int index,
	   int fixed, int var, int num_tocas)
{
    if(count > size){
	printf("%d\n", num_tocas);
	return;
    }

    if(count == 0) {
	fixed = arr[0];
	var = arr[0];
    }

    var = arr[var];
    
    if(var > size){
	var = arr[index];
    }

    if(var == fixed){

	num_tocas++;
	index++;

	fixed = arr[index];
	var = arr[index];
    }

    tocas(count+1, arr, size, index, fixed, var, num_tocas);

}

void make_arr(int count, int max, int *arr)
{
    if(count > max) return;
    
    scanf(" %d", &arr[count]);
    
    make_arr(count+1, max, arr);
}
