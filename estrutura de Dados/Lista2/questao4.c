#include <stdio.h>
#include <math.h>
#include "../../../LibsJPLS/vetores.h"
double avaliacaoDePolinomio_SemReturn(double* poli, int grau, double x,double *resultado){
    for (int i = 0; i <= grau; i++)
    {
        *resultado= *resultado + (poli[i]*pow(x,i));
    }
    
    
}
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