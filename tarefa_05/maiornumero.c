#include <stdio.h>

void num(int n);

int main()
{
    num(0);

    return 0;
}
void num(int n)
{
    int x;
    scanf("%d", &x);

    if(!x){
	printf("%d", n);
	return;
    }

    if(x>n){
	n = x;
    }

    num(n);
}
