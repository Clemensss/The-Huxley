#include <stdio.h>

void eleicao(void);
int main()
{
    eleicao();

    return 0;
}
void eleicao(void)
{
    int n, n1, num;
    scanf("%d", &num);
    for(n=1; n<=num; n++){

	for(n1=1;n1<=n;n1++){
	    printf("%d ", n1);
	}

	printf("\n");
    }
}
