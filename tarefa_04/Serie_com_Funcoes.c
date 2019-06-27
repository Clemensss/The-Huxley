#include <stdio.h>

int fatiter(int x, int count, int max);
int eh_primo(int x);
int eh_primo_iter(int x, int count);
int fatorial(int x);
int proximo_primo(int y);
void mainloop(double soma, int count, int *px);

int main()
{
    int x;
    scanf("%d", &x);

    if(x == 0){
	printf("0.00\n");
    }else{
	mainloop(0, 1, &x);
    }

    return 0;
}

void mainloop(double soma, int count, int *px)
{
    int fact, primo;
    double temp;

    if(count > *px){
	printf("%.2lf\n", soma);
	return;
    }

    fact = fatorial(count);

    if(count >= 2){
	primo = proximo_primo(count);
    }else{
	primo = 1;
    }

    temp = (double)(fact)/(double)(primo);

    if(count == *px){
	printf("%d!/%d\n",  count, primo);
    }else{
	printf("%d!/%d + ", count, primo);
    }

    count++;
    mainloop(temp + soma, count, px);
}


//---------primos----------

int proximo_primo(int count)
{
    if(count == 1){
	return 1;
    }else if(eh_primo(count)){
	return count;
    }

    count++;
    proximo_primo(count);    
}
int eh_primo(int x)
{
    return eh_primo_iter(x, 2);
}
int eh_primo_iter(int x, int count)
{
    if(x == 2 || x == 3 ||
       x == 5 || x == 7 ){

        return 1;

    }else if(x%count == 0 || x == 1){
       
	return 0;
    }
    else if(count == x-1){

	return 1;
    }
    eh_primo_iter(x, count+1);
}

//----------fatorial---------

int fatorial(int x)
{
    return fatiter(1,1,x);
}
int fatiter(int x, int count, int max)
{
    if(max == 1){	
	return 1;
    }
    else if(count>max){
	return x;
    }
    return fatiter(x*count, count+1, max);
}
