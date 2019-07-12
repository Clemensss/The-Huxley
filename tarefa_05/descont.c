#include <stdio.h>

void black(int count, int total);

int main()
{
    black(0, 0);
    return 0;
}

void black(int count, int total)
{
    if(count > 4){
	printf("%d\n", total);
	return;
    }

    double num, desc, porc;
    scanf("%lf %lf", &num, &desc);
    porc = (num*20.0)/100.0;

    if((desc+porc)==num){
	total+=1;
    }

    black(count+1, total);
}
