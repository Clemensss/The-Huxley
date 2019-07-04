#include <stdio.h>

void carros(float total, int casas);

int main()
{
    carros(0,0);

    return 0;
}
void carros(float total, int casas)
{
    int n;
    scanf("%d", &n);
    
    if(n == 999){
	printf("%f\n%d\n", total, casas);
	return;
    }

    if(n > 2){
	total += ((n-2)*12.89);
	casas+=1;
    }
    carros(total, casas) ;
}
