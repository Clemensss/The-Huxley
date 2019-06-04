#include <stdio.h>

long long fact_iter(long long n, int count, int max);
int mountarray(int *arr, int count);
void printfact(int count, int man, int *arr);
int main()
{
    int arr[13], max;
    max = mountarray(arr,0);
    printfact(0,max,arr);
    return 0;
}
long long fact_iter(long long n, int count, int max)
{
    if(count > max){
	return n;
    }
    long long n2 = n*count;
    count++;
    fact_iter(n2,count,max);
}
void printfact(int count, int max, int *arr)
{
    printf("%lld\n",fact_iter(1,1, arr[count]));
    count++;
    if(count<max){
	printfact(count,max,arr);
    }
}
int mountarray(int *arr, int count)
{
    int num;
    int max = count;
    scanf("%d",&num);
    if(num == -1 || num > 12){
	return max;
    }
    arr[count] = num;
    count++;
    mountarray(arr,count); 
}
