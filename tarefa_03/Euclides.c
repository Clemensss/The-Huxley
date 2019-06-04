#include <stdio.h>

int itereu(int a, int d);
void printeu(int n, int count);
int main()
{	
    int num;
    scanf("%d", &num);
    printeu(num,0);
    return 0;
}
int itereu(int a, int d)
{
    int Q, R;
    Q = a/d;
    R = a%d;
    if(R==0){
	return d;
    }
    itereu(d, R);
}
void printeu(int n, int count)
{ 
    int a,d,i;
    scanf("%d%d",&a,&d);
    printf("MDC(%d,%d) = %d\n",a,d,itereu(a,d));
    count++;
    if(count<n){
	printeu(n,count);
    }
}
