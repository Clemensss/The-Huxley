#include <stdio.h>

void loop(int *arr, int count, int maior, int menor);

void make(int *arr, int count);

int main()
{
    int arr[10], num;
    make(arr, 0);

    scanf("%d", &num);

    loop(arr, 0, num, 0);

    return 0;
}
void loop(int *arr, int count, int num, int vezes)
{
    if(count == 10){
	printf("%d\n", vezes);
	return;
    }

    if(arr[count] == num){
	vezes++;
    }

    loop(arr, count+1, num, vezes);
}
void make(int *arr, int count)
{
    if(count == 10) {
	return;
    }

    scanf("%d", &arr[count]);
    make(arr, count+1);
}
