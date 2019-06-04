#include <stdio.h>
#define MAX 15

int contador(char* str);
int countiter(int num, char* str, int count, int max);
int main()
{
    char *str;
    str=NULL;
    contador(str);
    return 0;
}
int contador(char* str)
{
    /*Uses the function getline found in the gnu
    compiler, which takes a string from stream and stores it
    into a buffer*/
    size_t bufasfuk = 0;
    int res = getline(&str, &bufasfuk,stdin); 
    printf("%d\n", countiter(0, str, 0, res));
    return res;
}
int countiter(int num, char* str, int count, int max)
{
    int conv = str[count];
    count++;
    if(count > max){
	return num;
    }
    if((conv-48)==0 || ((conv-48)%2)==0){
	num++;
	countiter(num, str, count, max);
    }
    countiter(num, str, count, max);
}   
