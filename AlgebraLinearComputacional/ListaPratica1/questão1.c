#include<stdio.h>
#define MAX 10000
void incluirVetor(float vetor[], int n,char nome){

 for (int i = 0; i < n; i++)
    {
        printf("Digite o valor de %c%d: ",nome,i);
        scanf("%f",&vetor[i]); 
    }
}
void imprimirVetor(float vetor[],int n){
     printf("O vetor final e : Y = (");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ",vetor[i]);
    }
    printf(")");
}

int main(){
    int n=0;
    float x[MAX];
    float y[MAX];
    float a=0;
    printf("Digite o valor de a (que pertence aos reais): ");
    scanf("%f",&a);
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    incluirVetor(x,n,'X');
    incluirVetor(y,n,'Y');
    for (int i = 0; i < n; i++)
    {    
        y[i]=(a*x[i])+y[i];
        
    }
    imprimirVetor(y,n);
    return 0;
}