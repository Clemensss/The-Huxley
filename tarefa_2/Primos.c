#include <stdio.h>

int primoiter(int x,int count);
void printfact(int count, int max, int *arr);
int primocheck(int x);
int mountarray(int *arr, int count);
int main()
{
    int arr[50], max;
    max = mountarray(arr,0);
    printfact(0,max,arr);
    return 0;
}
void printfact(int count, int max, int *arr)
{
    printf("%d\n",primocheck(arr[count]));
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
    if(num == -1){
	return max;
    }
    arr[count] = num;
    count++;
    mountarray(arr,count);
}

int primocheck(int x)
{
    return primoiter(x,0);
}
int primoiter(int x,int count)
{
    int arr[4]={2,3,5,7};
    if(arr[count]==x || count==3){
	return 1;
    }else if(x%arr[count]==0 || x==1 ){
	return 0;
    }	 
    count++;
    return primoiter(x, count);
}
