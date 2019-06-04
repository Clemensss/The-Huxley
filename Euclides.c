#include <stdio.h>

int itereu(int a, int d);
void printeu(int n);
int main()
{	
    int num;
    scanf("%d", &num);
    printeu(num);
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
void printeu(int n)
{ 
    int a,d,i;
    for(i=0;i<n;i++){ 
	scanf("%d%d",&a,&d);
	printf("MDC(%d,%d) = %d\n",a,d,itereu(a,d));
    }
}
