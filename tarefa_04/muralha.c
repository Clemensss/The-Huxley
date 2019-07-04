#include <stdio.h>
#include <stdlib.h>

void muralha(int moedas, int n, int x, int y,
	    int oldn, int count, int oldx);
int main()
{
    int n;
    scanf("%d\n", &n); 
    
    muralha(0, n, 0, 0, 0, 0, 0);

    return 0;
}

void muralha(int moedas, int n, int x, int y,
	    int oldn, int count, int oldx)
{
    if(count == n){
	printf("%d\n", moedas);
	return;
    }
    
    char c; 
    scanf("%c\n", &c);


    if(c == 'C'){
	y+=1;
    }else if(c == 'D'){
	x+=1;
    }

    int temp = y-x;

    printf("count: %d\n", count);

    if(abs(temp)==1 && oldn == 0 && count > 0 && temp != oldx){
	
	moedas+=1;
    }

    oldx = oldn;
    muralha(moedas, n, x, y, temp, count+1, oldx);
}

