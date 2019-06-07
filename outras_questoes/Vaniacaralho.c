#include <stdio.h>
#include <math.h>

int check(int num);
double pow(double x, double y);
int vania(int num, int count);
int iter(int num);
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n",iter(a));

    return 0;
}
int vania(int num, int count)
{
    int temp;
    int past = pow(10.0,(double)(count-1))-1;
    printf("past %d\n", past);
    if(count == 2){
	return (count*(num-9)+9);
    }
    temp = count*(num-past);
    count--;
    return temp+vania(past, count);
    
    
}
int iter(int num)
{
    int count = check(num);
    return vania(num, count);
}
int check(int num)
{
    int temp = num;
    int check = num;
    int i=1;
    while(check >= 10){
	check = temp/10;
	temp = check;
	i++;
    }
    return i;
}

