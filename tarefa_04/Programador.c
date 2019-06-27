#include <stdio.h>
#include <math.h>

void saber(int a, int b, int *c, int *d);
void doloop(void);
void loop(int count, int max,int *oldb, int c, int d, int *dia);
void printdia(int dia);

int main()
{
    doloop();  
    return 0;
}
void doloop(void)
{
    int a=0, b=0, c=0;
    loop(0, 7, &b, 0, 0, &c);
}
void saber(int a, int b, int *c, int *d)
{
    if(a>=5){
	(*c)++;
    }

    if(b >= 100){
	(*d)++;
   }
}
void loop(int count, int max,int *oldb, int c,
	  int d, int *dia)
{
    if(count >  max){
	printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n",c);
	printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n",d);
	printdia((*dia));
	return;
    }

    int a, b;
    scanf("%d %d", &a, &b);

    if(b>(*oldb)){
	*dia = count;	
    }

    saber(a,b,&c,&d);
    loop(count+1, 7, &b, c, d, dia);
}
void printdia(int dia)
{
    if(dia == 0)
	printf("DIA QUE MAIS PRODUZIU: DOMINGO\n");
    else if(dia == 1)
	printf("DIA QUE MAIS PRODUZIU: SEGUNDA\n");
    else if(dia == 2)
	printf("DIA QUE MAIS PRODUZIU: TERCA\n");
    else if(dia == 3)
	printf("DIA QUE MAIS PRODUZIU: QUARTA\n");
    else if(dia == 4)
	printf("DIA QUE MAIS PRODUZIU: QUINTA\n");
    else if(dia == 5)
	printf("DIA QUE MAIS PRODUZIU: SEXTA\n");
    else if(dia == 6)
	printf("DIA QUE MAIS PRODUZIU: SABADO\n");
}       

