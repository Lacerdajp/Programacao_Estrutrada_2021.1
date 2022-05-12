#include <stdio.h>
#include <math.h>
double incluir_vetorReais(int n, double* v ){
    for (int i = 0; i < n; i++)
    {
        printf("numero %i : \n",i);
        scanf("%lf",&v[i]);
        printf("%.2lf\n", v[i]);

    }
    return *v;
} 
double avaliacaoDePolinomio(double* poli, int grau, double x){
    double resultado= 0;
    for (int i = 0; i <= grau; i++)
    {
        resultado= resultado+ (poli[i]*pow(x,i));

    }
    
    return resultado;
}
int main(){
    double  poli[]={};
    double resultado=0,x=0;
    int grau=0;
    scanf("%d", &grau);
    *poli=incluir_vetorReais((grau+1),poli);
    scanf("%lf",&x); 
    resultado= avaliacaoDePolinomio(poli,grau,x);
    printf("P(%.2lf) = %.2lf",x,resultado);
    return 0;
}