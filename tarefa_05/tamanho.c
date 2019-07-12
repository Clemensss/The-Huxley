#include <stdio.h>

int tamanho(long long num, int total);
int coisa(int count, int n, int max);
void loop(void);

int main()
{
    loop();
    
    return 0;
}
void loop(void)
{
    int x, y, max;
    int retx, rety;

    if(scanf("%d %d", &x, &y) == EOF) return;

    retx = x; rety = y;

    if(y > x){
	int temp = y;
	y = x;
	x = y;
    }

    max = coisa(retx, rety, 0);
    printf("%d %d %d\n", x, y, max);

    loop();
}
int coisa(int count, int n, int max)
{
    if(count > n){ 
	return max;
    }

    int num = tamanho(count, 0);
    if(num>max){
	max = num;
    }
    
    return coisa(count+1, n, max);
}

int tamanho(long long num, int total)
{
    if(num == 1){
	return total+1;
    }
    
    if(num%2 == 0) num = num/2; 
    else num = ((3*num)+1);
    
    return tamanho(num, total+1);
}
