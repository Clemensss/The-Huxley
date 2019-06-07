#include <stdio.h>
#include <math.h>

int check(int num);
double pow(double x, double y);
long long vania(long long num, int count);
long long iter(long long num);
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n",iter(a));

    return 0;
}
long long vania(long long num, int count)
{
    long long temp;
    long long past = pow(10.0,(double)(count-1))-1;
    printf("past %d\n", past);
    if(count == 2){
	return (count*(num-9)+9);
    }
    temp = count*(num-past);
    count--;
    return temp+vania(past, count);
}
long long iter(long long num)
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

