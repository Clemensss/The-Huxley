#include <stdio.h>

void loop(int count, int *countc, int *countp);
void cafe(int i, char c, int *countp, int *countc);

int main()
{
    int countc=0, countp=0;
    loop(0, &countc, &countp);


    return 0;
}
void cafe(int i, char c, int *countc, int *countp)
{
    if(c=='G' || c=='g'){
	(*countc)+=i;
    }else{
	(*countp)+=i;
    }
}
void loop(int count, int *countc, int *countp)
{
    if(count == 7){
	int total = ((*countc)*16)+((*countp)*10);
	float cada = 2*(total/7.0);
	printf("%d\n%.f\n",total,cada);
	return;
    }

    int i; char c;
    scanf("%d\n%c", &i, &c);
    cafe(i, c, countc, countp);

    loop(count+1, countc, countp);
}


   
