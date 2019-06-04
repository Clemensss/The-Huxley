#include <stdio.h>
#define MAX 15

int contador(void);
void arraio(int arr[]);
int main()
{
    printf("%d\n",contador());
    return 0;
}
int contador(void)
{
    int i=0;
    int count=0;
    /*Uses the function getline found in the gnu
    compiler, which takes a string from stream and stores it
    into a buffer*/
    char *str=NULL, conv;
    size_t bufasfuk = 0;
    getline(&str, &bufasfuk,stdin); 
	while(1){
	conv = str[i];
	i++;
	if((conv-48)==0 || ((conv-48)%2)==0){
	    count++;
	}
	if(str[i]=='\0'){
	    break;
	}	
    }
    return count;
}
    
