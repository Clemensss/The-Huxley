#include <stdio.h>

int rickiter(int n,int t, int count, int indic);
void rickq(int n, int t);
int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    rickq(n,t); 
    return 0;
}
void rickq(int n, int t)
{
    printf("%d", rickiter(n,t,0,0));
}
int rickiter(int n,int t, int count, int indic)
{   
    if(count==t){
	return n;
    }else{
	
	if(indic==0){
	    indic=1;
	    count++;
	    rickiter((n+3),t,count,indic); 
	}else{
	    indic=0;
	    count++;
	    rickiter((n+(n%5)),t,count,indic);
	}
    }
}
