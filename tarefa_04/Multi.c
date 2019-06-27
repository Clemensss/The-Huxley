#include <stdio.h>

void multi(int x, int a, int b, int *count);
int main()
{
    int x, a, b, count=0;
    scanf("%d%d%d", &x, &a, &b);
    multi(x, a, b, &count);

    if(count == 0) printf("INEXISTENTE\n");
    
    return 0;
}
void multi(int x, int a, int b, int *count)
{
    if(a > b) return;

    if(!(a%x)){
	printf("%d\n", a);
	(*count)++;
    }
    multi(x, a+1, b, count);
    
}
