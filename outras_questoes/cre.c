#include <stdio.h>

void cre(int *small, float *oldc, float m, float soma);

int main()
{
    int small = 0;
    float oldc = 0;

    cre(&small, &oldc, 0, 0);

    return 0;
}

void cre(int *small, float *oldc, float m, float soma)
{
    int mat; 
    float c;
    scanf("%d", &mat);

    if(mat == 999){
	float media = soma/m;
	printf("%d\n%.2f\n", *small, media);
	return;
    }

    scanf("%f", &c);

    if(c<=*oldc || m == 0){
	*oldc = c;
	*small = mat;
    }


    soma += c; 
    cre(small, oldc, m+1, soma);
}    
