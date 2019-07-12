#include <stdio.h>

void serie(int count, int n, double total, double num);

int main()
{
    int n;
    scanf("%d", &n);
    serie(2, n, 1, 2);

    return 0;
}
void serie(int count, int n, double total, double num)
{
    if(count > n){
    	printf("S: %.2lf\n", total);
	return;
    }
    
    total += num/((count/2.0)*3);
    num *= 2.0;
    count++;

    if(count > n){
    	printf("S: %.2lf\n", total);
	return;
    }

    serie(count+1, n, total+((count)/num), num*2);
}
