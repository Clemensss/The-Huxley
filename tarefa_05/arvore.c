#include <stdio.h>

void arvore(int count, float total);
int main()
{
    float x;
    scanf("%f", &x);
    arvore(0, x);

    return 0;
}
void arvore(int count, float total)
{
    if(count > 7) {
	printf("%.2f\n%.2f\n", total, total/20.0);
	return;
    }
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    a *= b;

    arvore(count+1, total+a);
}
