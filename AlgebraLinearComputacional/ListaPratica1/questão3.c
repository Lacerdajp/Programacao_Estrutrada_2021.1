#include<stdio.h>
#define MAX 700
void incluirVetor(float vetor[], int n,char nome){

 for (int i = 1; i <= n; i++)
    {
        printf("Digite o valor de %c%d: ",nome,i);
        scanf("%f",&vetor[i]); 
    }
}
void incluirMatriz(float matriz[MAX][MAX],int linha,int coluna){
    for (int i = 1; i <= linha; i++)
    {
        printf(" Digite os %d valores da linha %d,respectivamente : ",coluna,i);
        for (int  j = 1; j <= coluna; j++)
        {
            scanf("%f",&matriz[i][j]);   
            
        }
        
    }
}
void imprimirMatriz(float matriz[MAX][MAX],int linha,int coluna){
    for (int i = 1; i <= linha; i++)
    {
        for (int  j = 1; j <= coluna; j++)
        {
            printf("%.2f",matriz[i][j]);   
        }
        printf("\n");
        
    }
}

void imprimirVetor(float vetor[],int n){
     printf("O vetor final e : Y = (");
    for (int i = 1; i <= n; i++)
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
    float ax[MAX];
    float a[MAX][MAX];
    printf("Digite o valor de n: ");
    scanf("%d",&nColunas);
    printf("Digite o valor de m: ");
    scanf("%d",&mLinhas);
    printf("Preenchendo o Vetor X:\n ");
    incluirVetor(x,nColunas,'X');
    printf("Preenchendo o Vetor Y:\n");
    incluirVetor(y,mLinhas,'Y');
    printf("Preenchendo a matriz A: \n");
    incluirMatriz(a,mLinhas,nColunas);
   for (int i = 1; i <= nColunas; i++)
    {
        for (int j = 1; j <= mLinhas; j++)
        {
            if (i==1)
            {
                ax[j]=a[j][i]*x[i];
            }else{
                ax[j]=ax[j]+(a[j][i]*x[i]);
            }
        }
    }
    for (int i = 1; i <= mLinhas; i++)
    {
         y[i]=ax[i]+y[i];
    }
    
    
    imprimirVetor(y,mLinhas);

    return 0;
}