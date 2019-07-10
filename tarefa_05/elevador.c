#include <stdio.h>

void elevador(int L, int C, int total, int count);

int main()
{
    int c, l;
    scanf("%d%d", &l, &c);
    elevador(l, c, 0, 0);

    return 0;
}
void elevador(int L, int C, int total, int count)
{
    if(count == L){
	printf("N\n");
	return;
    }
    int x, y;
    scanf("%d%d", &x, &y);

    total-=x;
    if(total > C){
	printf("S\n");
	return; 
    }

    total+=y;
     if(total > C){
	printf("S\n");
	return; 
    }
    
    elevador(L, C, total, count+1);

}
