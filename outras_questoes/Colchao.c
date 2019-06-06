#include <stdio.h>

void tama(int a, int b, int c, int h, int l);
int main()
{
    int a,b,c,h,l;
    scanf("%d%d%d%d%d",&a,&b,&c,&h,&l);
    tama(a,b,c,h,l);
    return 0;
}
void tama(int a, int b, int c, int h, int l)
{
    if((h>=a && l>=b) || (h>=a && l>=c)
    || (h>=b && l>=a) || (h>=b && l>=c)
    || (h>=c && l>=b) || (h>=c && l>=a)){
	printf("S\n");
    }
    printf("N\n");
}
