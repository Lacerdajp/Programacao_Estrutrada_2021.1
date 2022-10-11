#include <stdio.h>
#include<math.h>
void inserirValores(double v[]){
    printf("Para ax(ao quadrado)+bx+c digite os valores:\n");
    for (int i = 0; i < 3; i++)
    {
        if(i==0){
            printf("Valor de a: ");
        }else if (i==1)
        {
             printf("Valor de b: ");
        }else{
             printf("Valor de c: ");
        }
        
        scanf("%lf",&v[i]);
    }

}
void calculoRaizes(double v[],double raizes[]){
    int delta=pow(v[1],2)-(4*v[0]*v[2]);
     if (delta < 0 || v[0] == 0)
    {
        printf("impossivel calcular");
    }else{
         raizes[0]= (-(v[1])+sqrt(delta))/(2*v[0]);
    raizes[1]= (-(v[1])-sqrt(delta))/(2*v[0]);
    }
   
}
int main(){
    double valores[3]={0,0,0};
    double raizes[2]={0,0};
    char desejo=0;
    do
    { 
        inserirValores(valores);   
    calculoRaizes(valores,raizes);
    if (raizes[0]!=0||raizes[1]!=0)
        {
             printf("As raizes da formula e :");
        }
    for (int i = 0; i < 2; i++){
        if (raizes[i]!=0)
        {
            printf("%.2lf ",raizes[i]);
        }
        
    }
    printf("\nDeseja inserir novos valores: (se sim digite S)");
    scanf("%s",&desejo);
    } while (desejo=='S'||desejo=='s');
    
   
}