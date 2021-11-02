#include <stdio.h>
int main(){
    int n=0;
    double n1=0, n2=0,n3=0,media=0;
    const double p1=2,p2=3,p3=5;
    printf("Digite o numero de testes:\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("digite 3 valores:\n");
        scanf("%lf %lf %lf",&n1,&n2,&n3);
        media=((n1*2)+(n2*3)+(n3*5))/(3+2+5);
        printf("A media ponderada  do e: %.1lf \n",media);

    }
    return 0;
}