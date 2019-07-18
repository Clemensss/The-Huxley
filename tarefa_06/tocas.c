#include <stdio.h>

void make_arr(int count, int max, int *arr);

void tocas(int *arr, int count, int max,
	   int liga, int index, int num_tocas);

int search(int *arr, int count, int max);

int main()
{
    int size;
    scanf("%d", &size);

    int arr[size]; 
    size--;
    
    make_arr(0, size, arr);

    tocas(arr, 0, size, 0, 0, 0);

    return 0;

}

void tocas(int *arr, int count, int max,
	   int liga, int index, int num_tocas)
{
    if(count > max+2){
	printf("%d\n", num_tocas);
	return;
    }

    liga = arr[index];

    //printf("map %d: %d %d\n", count, index, liga);
    if(liga == -1){
    
	num_tocas++;
	
	int temp = search(arr, 0, max);

	if(temp == -1){


	}else{

	    index = temp;
	}

    }else{

	arr[index] = -1;
	index = liga;
    }
    
    tocas(arr, count+1, max, liga, index, num_tocas);
    
}
	    
int search(int *arr, int count, int max)
{
    if(count > max){
	return -1;	
    }

    if(arr[count] != -1){
	return count;
    }
    search(arr, count+1, max);
}
void make_arr(int count, int max, int *arr)
{
    if(count > max) return;
    
    scanf(" %d", &arr[count]);
    
    make_arr(count+1, max, arr);
}
