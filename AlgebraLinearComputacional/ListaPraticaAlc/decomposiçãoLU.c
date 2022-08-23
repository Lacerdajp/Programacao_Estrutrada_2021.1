#include<stdio.h>

#define N 3
//struct
struct vector 
{
    int posicao;
    double valor;
};

typedef struct vector Vector;

void zerarmatriz(double matriz[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
           
            matriz[j][i]=0.0;
                
        }
        
    }
    
}
void imprimirMatriz(double matriz[N][N],double vetor[]){
        for (int i = 0; i < N; i++)
        {
           for (int j = 0; j < N; j++)
           {
               if (j==(N-1))
               {
                   printf("%.2lf = %.2lf\n",matriz[i][j], vetor[i]);
               }
               else{
                   printf("%.2lf ",matriz[i][j]);
               }
           }
           
        }
        
}
void incluirMatriz(double matriz[N][N]){
    zerarmatriz(matriz);
    for(int i=0; i<N;i++){

        for (int j = 0; j < N; j++)
        {
            if (i==j)
            {
                matriz[i][j]=0;
            }else if(i==0){
                matriz[i][j]=matriz[i][j-1]+1;
                
            }else if (j==0)
            {
                  matriz[i][j]=matriz[i-1][j]+1;
            }else if (matriz[i][j-1]==0)
            {
                  matriz[i][j]=matriz[i][j-1]+1;
            }
            else if (matriz[i][j-1]<matriz[i-1][j])
            {
                matriz[i][j]=matriz[i][j-1]+1;
            }
            else{
                matriz[i][j]=matriz[i-1][j]+1;
                
            }
            
            
        }
    }
}
//Vetores(doubles)

void zerarVetor(double vetor[]){

 for (int i = 0; i < N; i++)
    {
        vetor[i]=0.0;
    }
}
void imprimirVetor(double vetor[]){
        for (int i = 0; i < N; i++)
        {
            printf("X%d = %.2lf\n",i,vetor[i]);
               

               
           
        }
        
}
void incluirVetor(double vetor[]){
    zerarVetor(vetor);
    for (int i = 0; i < N; i++)
    {
        if (i==0)
        {
            vetor[i]=i+1;
        }
        else{
            vetor[i]=vetor[i-1]+1;
        }
        
        
    }
    

}

//Vetores(Vector)

void definirPosicao(Vector x[]){
    for (int i = 0; i < N; i++)
    {
        x[i].posicao=i;
        x[i].valor=0;
    }
}
void ordenarVector(Vector x[]){
    Vector aux;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
        if (x[i].posicao<x[j].posicao){
            aux=x[j];
            x[j]=x[i];
            x[i]=aux;

        }
        }
    }
    
}
void imprimirVector(Vector vetor[]){
        ordenarVector(vetor);
        for (int i = 0; i < N; i++)
        {
            printf("X%d = %.2lf\n",vetor[i].posicao,vetor[i].valor);
               

               
           
        }
        
}
void decomposicaoLU(double matriz[N][N], double vetor[],Vector x[]){
    double pivo;
    double mL=0;
    for (int iteracao = 1; iteracao < N; iteracao++)
    {   
    //   printf("\nNumero da Iteracao %d: Matriz antes das trocas de Linhas\n ",iteracao);
    //       imprimirMatriz(matriz,vetor); 
        
       
        //  printf("\nNumero da Iteracao %d: Matriz depos das trocas de Linhas\n ",iteracao);
        //   imprimirMatriz(matriz,vetor);
        //   printf("\n------------------------------------------------------------------------------------------------------------------\n");
        
        for (int linha = iteracao+1; linha < N; linha++)
        {
            mL=-matriz[linha][iteracao]/matriz[iteracao][iteracao];
            matriz[linha][iteracao]=-mL;
            for (int coluna = iteracao+1; coluna < N; coluna++)
            {
                matriz[linha][coluna]=matriz[linha][coluna]+(mL*matriz[iteracao][coluna]);
            }
            vetor[linha]=vetor[linha]+(mL*vetor[iteracao]);
            
        }
    }
}
int main(){
    
    double matriz[N][N];
    double vetor[N];
    Vector x[N];
    int escolha=0;
    definirPosicao(x);
    incluirVetor(vetor);
     zerarmatriz(matriz);
    for(int i=0; i<N;i++){

        for (int j = 0; j < N; j++)
        {
            scanf("%lf",&matriz[i][j]);
            
            
        }
    }
    imprimirMatriz(matriz,vetor);
    printf("\n");
        decomposicaoLU(matriz,vetor,x);
         imprimirMatriz(matriz,vetor);


    return 0;
}