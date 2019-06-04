#include <stdio.h>


int primoiter(int x);
void printfact(void);
int main()
{
    printfact();
    return 0;
}
void printfact(void)
{
    int arr[13], max, num, i;
    for(i=0; i<13; i++){
	max = i;
	scanf("%d",&num);
	if(num == -1){
	    break;
	}
	arr[i] = num;
    }
    for(i=0; i<max; i++){
	printf("%d\n", primoiter(arr[i]));
    }
}
int primoiter(int x)
{
    int arr[4]={2,3,5,7};
    int i;
    for(i=0;i<4;i++){
	if(arr[i]==x){
	    return 1;
	}else if(x%arr[i]==0 || x==1){
	    return 0;
	}	 
     }
     return 1;
}
