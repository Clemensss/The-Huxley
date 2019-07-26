#include <stdio.h>

void loopum(int count, int maxum, int maxdois);
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    loopum(1, x, y);
    printf("\n");
    return 0;
}
void loopum(int count, int maxum, int maxdois)
{
    if(count > maxdois){
	return;
    }

    if(count > maxum){
	maxum = maxdois;	
	printf("\n");
    }

    printf("%d ", count);
    loopum(count+1, maxum, maxdois);
}

