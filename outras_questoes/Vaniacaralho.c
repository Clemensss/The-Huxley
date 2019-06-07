#include <stdio.h>
#include <math.h>

int check(int num);
double pow(double x, double y);
long long vania(long long num, int count);
long long iter(long long num);
int main()
{
    long long a;
    scanf("%lld", &a);
    printf("%lld\n",iter(a));

    return 0;
}
long long vania(long long num, int check)
{
    long long temp = 0;
    long long var = 1;
    int count=1;
    long long thing = pow(10.0,(double)(check-1))-1;
    while(count<check){
	long long past = pow(10.0,(double)(count))-1;
	long long past2 = pow(10.0,(double)(count-1))-1;
	var = temp;
	temp = count*(past-past2) + var;
	count++;
    }
    return check*(num-thing) + temp;
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

