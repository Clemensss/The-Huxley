#include <stdio.h>

int itereu(int a, int d);
int main()
{
    int num, num2;
    scanf("%d%d",&num,&num2);
    printf("%d\n", itereu(num, num2));
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
