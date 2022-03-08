#include <stdio.h>
#include "../../../LibsJPLS/polinomios.h"
#include "../../../LibsJPLS/vetores.h"
int main(){
    double  poli[]={};
    double resultado=0,x=0;
    int grau=0;
    scanf("%d", &grau);
    *poli=incluir_vetorReais((grau+1),poli);
    scanf("%lf",&x); 
    avaliacaoDePolinomio_SemReturn(poli,grau,x,&resultado);
    printf("P(%.2lf) = %.2lf",x,resultado);
    return 0;
}