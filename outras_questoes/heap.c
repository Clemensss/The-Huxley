#include <stdio.h>
#include <stdlib.h>

char* inputread(void);
void printes(int *arr, int len);
void printarr(int *arr, int len, int opcao);
int stringparse(char *s);
void makearr(int *arr, char *s, int count);

void swap(int *elone, int *eltwo);
void heapify(int *arr, int len);
int heapcond(int *arr, int n, int len);
int pop(int *arr, int *len);
void heapsort(int *arr, int len);

int main()
{
    char *s;
    int len;
    s = inputread();
    len = stringparse(s);

    int arr[len];
    makearr(arr, s, len);

    printes(arr, len);
    heapsort(arr, len);
    printes(arr, len);
    return 0;
}

//-------------------------- Coisas de Heap ---------------

void heapsort(int *arr, int len)
{
    int temp = len-1;    
    
    int i;
    for(i=0; temp>0; i++){
	pop(arr, &temp);
	//printarr(arr, temp, 1);
    }
}

int pop(int *arr, int *len)
{
    int temp = arr[0];
    swap(&arr[0], &arr[*len]);
    (*len)--;
    heapify(arr, *len);
    return temp;
}

void heapify(int *arr, int len)
{
    int i, count = 0;
    while(1){

	for(i=1; i<len; i++){
	    count += heapcond(arr, i, len);
	}

	if(count == 0) break;
	else count = 0;
    }
}

int heapcond(int *arr, int n, int len)
{
    int count = 0;

    int n2 = n << 1;
    int n1 = n2 - 1;
    n -= 1;
    if(n1 > len || n2 > len) return 0;
     
    while(1){

	if(arr[n] < arr[n1]){

	    swap(&arr[n], &arr[n1]);
	    count++;

	}else if(arr[n] < arr[n2]){

	    swap(&arr[n], &arr[n2]);
	    count++;
	}

	else break;
	
    }

    return count;
}

void swap(int *elone, int *eltwo)
{
    int temp;
    temp = *eltwo;
    *eltwo = *elone;
    *elone = temp;
}

//----------------Coisas inuteis--------------------

void printarr(int *arr, int len, int opcao)
{   
    int i;
    switch(opcao){

	case 0:

	    printf("Estado inicial: %d ", arr[0]);

	    printes(arr, len);

	    break;

	case 1:

	    printf("Estado Atual da Heap: %d ", arr[0]);

	    printes(arr, len+1);
	    if(len > 0)
		printf("Maior elemento neste passo: %d\n", arr[0]);


	    break;
	case 3:

	    printf("Resultado Final: %d ", arr[0]);

	    printes(arr, len);

	    break;
    }
    
}

void printes(int *arr, int len)
{
    int i;
    for(i=1; i<len; i++){
	printf("%d ", arr[i]);
    }    
    printf("\n");

}

void makearr(int *arr, char *s, int count)
{
    char *cp;
    char *end;
    long num;

    int i;
    for(i=0; i<count; i++){

        num = strtol(s, &end, 10);
	arr[i] = (int)(num);
	
	printf("num %d\n", num);
        s = end;

    }

}

int stringparse(char *s)
{
    int count = 0;
    char *end;
    char *sus;
    
    sus = s;

    long i;

    for (i = strtol(sus, &end, 10);
         sus != end;
         i = strtol(sus, &end, 10)){

        sus = end;

	count++;
    }
    return count;
}


char* inputread(void)
{

    char *lineptr;                                  
    size_t bufasfuk = 0;

    lineptr = NULL;
    getline(&lineptr, &bufasfuk,stdin);

    return lineptr;
}
