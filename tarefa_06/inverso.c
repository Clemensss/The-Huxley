#include <stdio.h>

void loop(char *arr, int max);
int make(char *arr, int max);

int main()
{
    char str[255];
    int size;

    size = make(str, 0);

    loop(str, size);
    printf("\n");

    return 0;
}
void loop(char *str, int max)
{
    if(0 > max) {
	return;
    }

    printf("%c", str[max]);
    loop(str, max-1);
}


int make(char *str, int count)
{
    char c;
    scanf("%c", &c);

    if(c == '\0'){
	return count;
    }
   
    str[count]=c;
    make(str, count+1);
}
