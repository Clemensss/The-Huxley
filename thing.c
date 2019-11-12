#include <stdio.h>
#include <stdlib.h>

#define DASH "---------------------------------------"

void swap(int* one, int* two);
void shuffle(int *arr, size_t n);
void make(int *arr, int size);
void printarr(int *arr , int size);
void quick(int *v, int size, int iter);

int main()
{
    int size = 10000;
    int arr[size];
    make(arr, size);
    printarr(arr, size);
    
    quick(arr, size, 0);
    printarr(arr, size);
    printarr(arr, size);
    return 0;
}

void shuffle(int *arr, size_t n)
{
    if(n > 1)
    {
	size_t i;
	for(i = 0; i < n - 1; i++)
	{
	    size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
	    swap(&arr[j], &arr[i]);
	}
    }
}

void printarr(int *arr , int size)
{
    for(int i = 0; i < size-1; i++)
    {
	printf("%d ", arr[i]);
    }
    printf("%d\n", arr[(size-1)]);
    printf("%s\n", DASH);
}

void make(int *arr, int size)
{
    int j=1;
    for(int i = 0; i < size; i++)
    {
	if(j)
	{ 
	    arr[i] = i;
	    j=0;
	}
	else
	{ 
	    arr[i] = i-1;
	    j=1;
	}
    }
    shuffle(arr, size);
}

void quick(int *v, int size, int iter)
{
    int num = 0;
	iter++;

    if (size <= 1)
	return;
    else 
    {
	int pivot = v[size / 2];
	int a = 0;
	int b = size -1;
	
	while(a < b)
	{
	    while (v[a] < pivot) a++;
	    while (v[b] > pivot) b--;

	    if(a < b)
	    {
		swap(&v[a], &v[b]);

		num++;
		printf("num: %d\n", num);
		printf("%s\n", DASH);

		printf("iter: %d\n", iter);

		printarr(v, size);
		a++;
	    }

	}
	quick(v,b, iter);
	quick(v+a, size -a, iter);
    }
}
void swap(int* one, int* two)
{
    int t;
    t = *one;
    *one = *two;
    *two = t;
}
