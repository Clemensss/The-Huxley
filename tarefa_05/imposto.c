#include <stdio.h>

int main()
{
    double dolar, icms, produto, frete;
    scanf("%lf %lf %lf %lf", &dolar, &icms, &produto, &frete);
 
    int coisa = 0;

    frete *= dolar;
    icms= icms/100.0;

    double total = dolar * produto + frete;

    printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n", 
	    dolar, produto*dolar, frete, total);
    
    if(produto > 2500){
	total = total - frete;
	coisa = 1;
    }
    
    double import = (total * 60)/100.0;

    icms = ((total + import)/(1 -icms)) * icms;
    
    double totalim = import + icms;

    total = total + frete + totalim;

    printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n", import,icms,import+icms, total);

    if(coisa){
	printf("Impostos calculados sem o frete\n");
    }else
	printf("Impostos calculados com o frete\n");

    return 0;
}
