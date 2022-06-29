#include<stdio.h>
#define MAX 100000
void incluirVetor(float vetor[], int n,char nome){

 for (int i = 0; i < n; i++)
    {
        printf("Digite o valor de %c%d: ",nome,i);
        scanf("%f",&vetor[i]); 
    }
}
void incluirMatriz(float **matriz,int linha,int coluna){
    for (int i = 0; i < linha; i++)
    {
        printf("")
        for (int  j = 0; j < coluna; j++)
        {
            
        }
        
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
    int mLinhas=0;
    int nColunas=0;
    float x[MAX];
    float y[MAX];
    float a[MAX][MAX];
    

    return 0;
}