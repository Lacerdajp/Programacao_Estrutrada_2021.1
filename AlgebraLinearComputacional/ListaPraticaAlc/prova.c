#include<stdio.h>

#define N 21
//struct
struct vector 
{
    int posicao;
    double valor;
};
typedef struct vector Vector;

//Matrizes
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
//funções utilizaveis em todos
void calcularResultante(double matriz[N][N],double vetor[],Vector x[]){
    double soma=0;
    for (int linha = N-1; linha >=0; linha--)
    {   
        soma=0;
        for (int coluna = N-1; coluna >=0; coluna--)
        {
            if (linha==coluna)
            {
                x[coluna].valor=(vetor[linha]-soma)/matriz[linha][coluna];
                break;
            }
            else{
                soma=soma+(matriz[linha][coluna]*x[coluna].valor);
            }
        }
    }  
}
//eliminação por pivoteamento parcial
double definirPivoParcial(double matriz[N][N],double vetor[],int iteracao){
    double pivo;
    double aux;
    int linhaMaior;
    pivo=matriz[iteracao][iteracao];
        linhaMaior=iteracao;
        for (int linha = iteracao; linha < N; linha++)
        {
            if (matriz[linha][iteracao]>matriz[linhaMaior][iteracao])
            {
                linhaMaior=linha;
               
                 
            }
        } 
        for (int coluna = 0; coluna < N; coluna++)
        {
                    aux=matriz[linhaMaior][coluna];
                    matriz[linhaMaior][coluna]=matriz[iteracao][coluna];
                    matriz[iteracao][coluna]=aux;
        }
         aux=vetor[linhaMaior];
         vetor[linhaMaior]=vetor[iteracao];
         vetor[iteracao]=aux;
    return pivo=matriz[iteracao][iteracao];


}

void pivoteamentoParcial(double matriz[N][N], double vetor[],Vector x[]){
    double pivo;
    double mL=0;
    //   imprimirMatriz(matriz);
    //    printf("\n");
    for (int iteracao = 0; iteracao < N; iteracao++)
    {   
        pivo=definirPivoParcial(matriz,vetor,iteracao);

        for (int linha = iteracao+1; linha < N; linha++)
        {
            mL=matriz[linha][iteracao]/pivo;
            for (int coluna = 0; coluna < N; coluna++)
            {
                matriz[linha][coluna]=matriz[linha][coluna]-(mL*matriz[iteracao][coluna]);
            }
            vetor[linha]=vetor[linha]-(mL*vetor[iteracao]);
            
        }
    }
    calcularResultante(matriz,vetor,x);
}
double definirPivoTotal(double matriz[N][N],double vetor[],int iteracao,Vector x[]){
    double pivo;
    double aux;
    int auxInt;
    int c=0;
    int maior=iteracao;
    double maiorValor;
    pivo=maiorValor=matriz[iteracao][iteracao];
        for (int coluna = iteracao; coluna < N; coluna++)
        {
            if (matriz[iteracao][coluna]>maiorValor)
            {
                maiorValor=matriz[iteracao][coluna];
                c=1;
                maior=coluna;
            }
        } 
        for (int linha = 0; linha < N; linha++)
        {
            if (matriz[linha][iteracao]>=maiorValor)
            {
                maiorValor=matriz[linha][iteracao];
                c=2;
                maior=linha;
            }
        }
        
        if (c==1)
        {
            //  printf("\nFOI TROCADO Colunas %d e %d",iteracao, maiorColuna);
            for (int linha = iteracao; linha < N; linha++)
            {
                aux=matriz[linha][maior];
                    matriz[linha][maior]=matriz[linha][iteracao];
                    matriz[linha][iteracao]=aux;
            }
            auxInt=x[iteracao].posicao;
            x[iteracao].posicao=x[maior].posicao;
            x[maior].posicao=auxInt;
            
            
        }
        
        if (c==2)
        {
        // printf("\nFOI TROCADO LINHAS %d e %d",iteracao, maiorLinha);
        for (int coluna = iteracao; coluna < N; coluna++)
        {
                    aux=matriz[maior][coluna];
                    matriz[maior][coluna]=matriz[iteracao][coluna];
                    matriz[iteracao][coluna]=aux;
        }
         aux=vetor[maior];
         vetor[maior]=vetor[iteracao];
         vetor[iteracao]=aux;
        }
       
    return pivo=matriz[iteracao][iteracao];


}
void pivoteamentoTotal(double matriz[N][N], double vetor[],Vector x[]){
    double pivo;
    double mL=0;
    for (int iteracao = 0; iteracao < N; iteracao++)
    {   
    //    printf("\nNumero da Iteracao %d: Matriz antes das trocas de Linhas\n ",iteracao);
    //      imprimirMatriz(matriz,vetor); 
        
        pivo=definirPivoTotal(matriz,vetor,iteracao,x);
        // printf("\nNumero da Iteracao %d: Matriz depos das trocas de Linhas\n ",iteracao);
        //  imprimirMatriz(matriz,vetor);
        //  printf("\n------------------------------------------------------------------------------------------------------------------\n");
        
        for (int linha = iteracao+1; linha < N; linha++)
        {
            mL=matriz[linha][iteracao]/pivo;
            for (int coluna = 0; coluna < N; coluna++)
            {
                matriz[linha][coluna]=matriz[linha][coluna]+((-mL)*matriz[iteracao][coluna]);
            }
            vetor[linha]=vetor[linha]-(mL*vetor[iteracao]);
            
        }
    }
    calcularResultante(matriz,vetor,x);
}


int main(){
    
    double matriz[N][N];
    double vetor[N];
    Vector x[N];
    int escolha=0;
    definirPosicao(x);
    incluirVetor(vetor);
    incluirMatriz(matriz);
        printf("Escolha um metodo para ser resolvido: \n");
            printf("1.Eliminacao de Gauss, Pivoteamento Total\n");
            printf("2.Eliminacao de Gauss, Pivoteamento Parcial\n");
            printf("3. LU");
        
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            pivoteamentoTotal(matriz,vetor,x);
            
            imprimirMatriz(matriz,vetor);
            imprimirVector(x);
            break;
        case 2:
        pivoteamentoParcial(matriz,vetor,x);
         imprimirMatriz(matriz,vetor);
        imprimirVector(x);
            break;
        default:
            escolha=0;
            break;
        }


    return 0;
}