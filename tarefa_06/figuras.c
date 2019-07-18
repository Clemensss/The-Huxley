#include <stdio.h>
void figuras(int *pcard, int *icard, int *calc, 
	     int count, int max);


int sumarr(int *arr, int max, int total);
int is_it_there(int *cards, int count, int num, int max);
int isit(int *arr, int count, int num, int max);
int parim(int n);
int main()
{
    int n;
    scanf("%d", &n);

    int pcard[n], icard[n];
    int calc[] = {0,0,0,0};
    
    figuras(pcard, icard, calc, 0, n-1);

    return 0;
}
void figuras(int *pcard, int *icard, int *calc, 
	     int count, int max)
{   
    if(count > max){
	int joao = sumarr(pcard, calc[2], 0);
	int maria = sumarr(icard, calc[3], 0);
	
	int soma;

	if(joao>maria) soma = joao;
	else soma = maria;
	printf("%d\n%d\n%d\n", calc[0], calc[1], soma);
	
	return;	
    }

    int temp;
    scanf("%d", &temp);

    if(parim(temp)){
	calc[0]++;

	int var = is_it_there(pcard, 0, temp, count);

	if(!var){
	    pcard[calc[2]] = temp;
	    calc[2]++;
	}
    }

    else{
	calc[1]++;

	int var = is_it_there(icard, 0, temp, count);

	if(!var){
	    icard[calc[3]] = temp;
	    calc[3]++;
	}
    }

    figuras(pcard,icard, calc, count+1, max);

}

int sumarr(int *arr, int max, int total)
{
    if(max < 0) return total;

    total += arr[max];
    sumarr(arr, max-1, total);
}

int is_it_there(int *cards, int count, int num, int max)
{
    int over = isit(cards, 0, num, max);


    if(over)return 1;
    
    return 0;
}

int isit(int *arr, int count, int num, int max)
{
    if(count > max) return 0;

    if(arr[count] == num) return 1;

    isit(arr, count+1, num, max);
}
int parim(int n)
{
    return !(n & 1);
}

