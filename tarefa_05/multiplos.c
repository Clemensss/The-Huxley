#include <stdio.h>

void multiplos(int x, int y, int count, int total);

int main()
{
    int x,y;
    scanf("%d%d", &x, &y);
    multiplos(x,y,0,0);
    return 0;
}
void multiplos(int x, int y, int count, int total)
{
    if(count == 50){
	printf("%d\n", total-1);
	return;
    }

    if((count%x) == 0 && (count%y) == 0){
	total += 1;
    }
    
    multiplos(x, y, count+1,total);
    
}
