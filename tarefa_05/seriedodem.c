#include <stdio.h>
#include <math.h>

void serie(int count, int n, double total);

int main()
{
    int n;
    scanf("%d", &n);
    serie(2, n, 1);

    return 0;
}
void serie(int count, int n, double total)
{
    if(count > n){
	printf("S: %.2lf\n", total);
	return;
    }
    
    int den, div;

    if(count%2){
	den = count;	
        div = pow(2, count-1);
    }else{
	den = pow(2, count-1);
	div = (count/2)*3;
    }

    total += ((double)(den)/(double)(div));
    serie(count+1, n, total);
    
}

