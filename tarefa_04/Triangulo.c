#include <stdio.h>

int triangulo(int x, int count);
int main()
{
    int x;
    scanf("%d", &x);
    if(triangulo(x, 0)){
	printf("Verdadeiro\n");	
    }else{
	printf("Falso\n");	
    }
    return 0;
}
int triangulo(int x, int count)
{
    if(x <= 0) return 0;

    int temp = count*(count+1)*(count+2);

    if(temp == x){
        printf("%d * %d * %d = %d\n", 
		count, count+1, count+2, x);
	return 1;
    }
    else if(count+3 == x){
	return 0;
    }

    return triangulo(x, count+1);
}
