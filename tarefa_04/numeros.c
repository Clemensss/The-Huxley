#include <stdio.h>

void loop(void);
int arrayfazer(int *arr, int count);
void printfarr(int *arr, int *num, int n, int count);

int main()
{
    loop();

    return 0;
}

void loop(void)
{
    int arr[1000], num, n;

    if(!arrayfazer(arr, 0)) return;

    scanf("%d", &n);
    printfarr(arr, &num, n, 0);
    loop();

}

int arrayfazer(int *arr, int count)
{
    if(count == 1000) return 1;

    int temp;
    scanf("%d", &temp);

    if(x == -1 && count == 0) return 0;

    arr[count]=temp;

    arrayfazer(arr, count+1);
}

void printfarr(int *arr, int *num, int n, int count)
{
    if(count == 1000){
	printf("%d appeared %d times\n", n, *num);
	return;
    }
    
    if(arr[count]==n){
	(*num)++;
    }
    printfarr(arr, num, n, count+1);
}
