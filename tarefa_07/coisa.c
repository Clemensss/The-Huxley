#include <stdio.h>

void loopum(int count, int num, int maxum, int maxdois, int z);
int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    loopum(1, 1, x, y, z);
    printf("\n");
    return 0;
}
void loopum(int count, int num, int maxum, int maxdois, int z)
{
    if(count > maxdois){
	return;
    }

    if(num > maxum){
	maxum += maxum;	
	printf("\n");
    }

    printf("%d ", count);
    loopum(count+z, num+1, maxum, maxdois, z);
}

