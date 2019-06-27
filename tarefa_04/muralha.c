#include <stdio.h>

void muralha(int moedas, int n,
	     int *px, int *py,
	     int count, int *din);

int main()
{
    int n, px=0, py=0, din=0;
    scanf("%d", &n); 

    muralha(0, n, &px, &py, 0, &din);

    return 0;
}

/* O *din muda pra 1 toda vez que o maluco 
   chega numa coordenada y-x=0, pq ai se o 
   valor de y - x for igual a 1, quer dizer
   que ele atravessou a muralha, se nao for 1
   ele nao conta como se tivesse atravessado
*/

void muralha(int moedas, int n,
	     int *px, int *py,
	     int count, int *din)
{
    if(count == n){
	printf("%d\n", moedas);
	return;
    }

    char c;
    scanf("%c", &c);

    if(c == 'C'){
	(*py)++;
    }else if(c == 'D'){
	(*px)++;
    }

    if((*py-*px) == 0 && count != 0) *din = 1;

    if((*py-*px) == 1 && *din == 1){
	moedas+=1;
	*din = 0;
    }

    muralha(moedas, n, px, py, count+1, din);
}

