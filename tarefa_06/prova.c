#include <stdio.h>

int ler_string(char *str, char *strcom, 
		int count, int total);

int timesap(int *arr, int max,
	    int count, int num, int vezes);
int timeloop(int *arr, int count, 
	     int max, int num, int vezes);

void ler(char *str, int count);
void notas(char *strcom, int alunos, int apro, int *maxarr);

int main()
{
    int maxarr[100];
    char strcom[11];

    ler(strcom, 0);

    notas(strcom, 0, 0, maxarr);

    return 0;
}

void notas(char *strcom, int alunos, int apro, int *maxarr)
{
    int num;
    scanf("%d\n", &num);

    if(num == 9999){

	double porc = (apro*100)/(double)(alunos);
	printf("%.1lf%\n", porc);

	int max = timesap(maxarr, (alunos-1), 0, 0, 0);
	printf("%.1f\n", (float)(max));

	return;
    }
    

    int nota;
    char str[11];

    ler(str, 0);
    nota = ler_string(str, strcom, 0, 0);

    maxarr[(num-1)] = nota;

    if(nota >= 6) 
	    apro++;
    
    printf("%d %.1f\n", num, (float)(nota));

    notas(strcom, num, apro, maxarr);
}

int ler_string(char *str, char *strcom, 
		int count, int total)
{
    if(count == 10){
	return total;
    }

    char temp1 = str[count];
    char temp2 = strcom[count];

    if(temp1 == temp2){	
	total++;
    }

    ler_string(str, strcom, count+1, total);
}

int timesap(int *arr, int max,
	    int count, int num, int vezes)
{
    if(count > max){
	return num;
    }
    
    int temp = arr[count];
    int vez_temp = timeloop(arr, 0, max, temp, 0);

    if(temp != num && vez_temp > vezes){
	num = temp;
	vezes = vez_temp;
    }

    timesap(arr, max, count+1, num, vezes);
}
int timeloop(int *arr, int count, 
	     int max, int num, int vezes)
{
    if(count > max) return vezes;
    
    if(arr[count] == num) vezes++;

    timeloop(arr, count+1, max, num, vezes);
}

void ler(char str[], int count)
{   
    if(count == 10){
	return;
    }

    scanf("%c ", &str[count]);
    ler(str, count+1);
}
