#include <stdio.h>

void swap(float *x, float *y);
void printarray(float *arr, int count);
void ord(float *arr, int count);
void makearry(float *arr, int count);

int main()
{
    float arr[4];
    makearry(arr, 0);
    ord(arr, 0);
    swap(&arr[0], &arr[3]);
    swap(&arr[3], &arr[2]);
    printarray(arr,0);

    return 0;
}

void printarray(float *arr, int count)
{
    if(count == 4) return;

    printf("%.2f\n", arr[count]);

    printarray(arr, count+1);
}

void ord(float *arr, int count)
{
    if(count == 3) return;

    float num1 = arr[count], num2 = arr[count+1];
    
    if(num1 > num2){
	swap(&num1, &num2);
    }

    ord(arr, count+1);
}

void makearry(float *arr, int count)
{
    if(count == 4) return;

    float n;
    scanf("%f", &n);
    arr[count] = n;

   makearry(arr, count+1);
}

void swap(float *x, float *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}
