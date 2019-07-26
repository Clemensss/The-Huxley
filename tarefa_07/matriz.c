#include <stdio.h>

int main()
{

    return 0;
}

void programa(int mat[3][3], int count, int j, int maior, int soma)
{

    if(j>2){
	return;
    }

    if(count > 2){
	count = 0;
	j++;
    }
    int coisa = mat[j][count];
    
    soma += coisa;
    if(coisa > maior) maior = coisa;

    programa(mat, count, j, maior, soma);
}
void ler(int count, int j, int mat[3][3])
{
    if(j > 2){
	return;
    }

    if(count > 2){
	count = 0;
	j++;
    }
    scanf("%d", &mat[j][count]);

    ler(count, j, mat);
}

