#include <stdio.h>

void divisor(int n, int count, int *num);

int main()
{
    int x, count=0;

    scanf("%d", &x);
    divisor(x, 1, &count);

    if(count){
	printf("%d\n", count);
    }else{
	printf("O numero nao possui divisores multiplos de 3!\n");
    }
    return 0;
}
void divisor(int n, int count, int *num)
{
    if(count > n || n==0) return;

    if(n%count == 0){	
	if(count%3==0)(*num)++;
    }
    divisor(n, count+1, num);
}
