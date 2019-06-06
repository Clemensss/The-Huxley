#include <stdio.h>
#include <math.h>

int check(int num);
double pow(double x, double y);
int vaniasuavadia(int num, int count);
int iter(int num);
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n",iter(a));

    return 0;
}
int vaniasuavadia(int num, int count)
{
    int c = count;
    if(num/10 <= 10){
	return (count*(num-9)+9);
    }
    int temp = num/(pow(10.0, (double)(count-1)));
    temp = temp*(pow(10.0, (double)(count-1)));
    printf("temp %d count %d\n", temp, count);
    printf("numero1 %d\n",vaniasuavadia(num-temp,(count--))); 
    return (c*((num)-vaniasuavadia(num-temp,(count--))))+(temp-1);
}
int iter(int num)
{
    int count = check(num);
    return vaniasuavadia(num, count);
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

