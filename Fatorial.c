#include <stdio.h>

int fact_iter(int n, int count, int max);
void printfact(void);
int main()
{
    printfact();
    return 0;
}
int fact_iter(int n, int count, int max)
{
    if(count > max){
	return n;
    }
    int pro = n*count;
    count++;
    fact_iter(pro,count,max);
}
void printfact(void)
{
    int arr[13], max, num, i;
    for(i=0; i<13; i++){
	max = i;
	scanf("%d",&num);
	if(num == -1 || num > 12){
	    break;
	}
	arr[i] = num;
    }
    for(i=0; i<max; i++){
	printf("%d\n",fact_iter(1,1, arr[i]));
    }
}
