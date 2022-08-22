#include<stdio.h>
#define n 21

//Matrizes
void zerarmatriz(double matriz[n][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           
            matriz[j][i]=0.0;
                
        }
        
    }
    
}
void imprimirMatriz(double matriz[n][n],double vetor[]){
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < n; j++)
           {
               if (j==(n-1))
               {
                   printf("%.2lf = %.2lf\n",matriz[i][j], vetor[i]);
               }
               else{
                   printf("%.2lf ",matriz[i][j]);
               }
           }
           
        }
        
}
void incluirMatriz(double matriz[n][n]){
    zerarmatriz(matriz);
    for(int i=0; i<n;i++){

        for (int j = 0; j < n; j++)
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
//Vetores

void zerarVetor(double vetor[]){

 for (int i = 0; i < n; i++)
    {
        vetor[i]=0.0;
    }
}
void imprimirVetor(double vetor[]){
        for (int i = 0; i < n; i++)
        {
            printf("X%d = %.2lf\n",i,vetor[i]);
               

               
           
        }
        
}
void incluirVetor(double vetor[]){
    zerarVetor(vetor);
    for (int i = 0; i < n; i++)
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
double definirPivoParcial(double matriz[n][n],double vetor[],int iteracao){
    double pivo;
    double aux;
    int linhaMaior;
    pivo=matriz[iteracao][iteracao];
        linhaMaior=iteracao;
        for (int linha = iteracao; linha < n; linha++)
        {
            if (matriz[linha][iteracao]>matriz[linhaMaior][iteracao])
            {
                linhaMaior=linha;
               
                 
            }
        } 
        for (int coluna = 0; coluna < n; coluna++)
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
void calcularResultante(double matriz[n][n],double vetor[],double x[]){
    double soma=0;
    for (int linha = n-1; linha >=0; linha--)
    {   
        soma=0;
        for (int coluna = n-1; coluna >=0; coluna--)
        {
            if (matriz[linha][coluna-1]==0.0||coluna==0)
            {
                x[coluna]=(vetor[linha]-soma)/matriz[linha][coluna];
                break;
            }
            else{
                soma=soma+(matriz[linha][coluna]*x[coluna]);
            }
            
           
        }
        
        
    }  
    
}
void pivoteamentoParcial(double matriz[n][n], double vetor[],double x[]){
    double pivo;
    double mL=0;
    //   imprimirMatriz(matriz);
    //    printf("\n");
    for (int iteracao = 0; iteracao < n; iteracao++)
    {   
        pivo=definirPivoParcial(matriz,vetor,iteracao);

        for (int linha = iteracao+1; linha < n; linha++)
        {
            mL=matriz[linha][iteracao]/pivo;
            for (int coluna = 0; coluna < n; coluna++)
            {
                matriz[linha][coluna]=matriz[linha][coluna]-(mL*matriz[iteracao][coluna]);
            }
            vetor[linha]=vetor[linha]-(mL*vetor[iteracao]);
            
        }
    }
    calcularResultante(matriz,vetor,x);
}
double definirPivoTotal(double matriz[n][n],double vetor[],int iteracao){
    double pivo;
    double aux;
    double maiorValor;
    int maiorLinha;
    int maiorColuna;
    pivo=maiorValor=matriz[iteracao][iteracao];
        maiorLinha=maiorColuna=iteracao;
        for (int coluna = iteracao; coluna < n; coluna++)
        {
            for (int linha = iteracao; linha < n; linha++)
            {
            if (matriz[linha][coluna]>maiorValor)
            {
                maiorValor=matriz[linha][coluna];
                maiorLinha=linha;
                maiorColuna=coluna;   
            }
            }
            
            
        } 
        if (maiorColuna!=iteracao)
        {
             printf("\nFOI TROCADO Colunas %d e %d",iteracao, maiorColuna);
            for (int linha = iteracao; linha < n; linha++)
            {
                aux=matriz[linha][maiorColuna];
                    matriz[linha][maiorColuna]=matriz[linha][iteracao];
                    matriz[linha][iteracao]=aux;
            }
            
        }
        
        if (maiorLinha!=iteracao)
        {
         printf("\nFOI TROCADO LINHAS %d e %d",iteracao, maiorLinha);
        for (int coluna = iteracao; coluna < n; coluna++)
        {
                    aux=matriz[maiorLinha][coluna];
                    matriz[maiorLinha][coluna]=matriz[iteracao][coluna];
                    matriz[iteracao][coluna]=aux;
        }
         aux=vetor[maiorLinha];
         vetor[maiorLinha]=vetor[iteracao];
         vetor[iteracao]=aux;
        }
       
    return pivo=matriz[iteracao][iteracao];


}
void pivoteamentoTotal(double matriz[n][n], double vetor[],double x[]){
    double pivo;
    double mL=0;
    for (int iteracao = 0; iteracao < n; iteracao++)
    {   
    //    printf("\nNumero da Iteracao %d: Matriz antes das trocas de Linhas\n ",iteracao);
    //      imprimirMatriz(matriz,vetor); 
        
        pivo=definirPivoTotal(matriz,vetor,iteracao);
        printf("\nNumero da Iteracao %d: Matriz depos das trocas de Linhas\n ",iteracao);
         imprimirMatriz(matriz,vetor);
         printf("\n------------------------------------------------------------------------------------------------------------------\n");
        
        for (int linha = iteracao+1; linha < n; linha++)
        {
            mL=matriz[linha][iteracao]/pivo;
            for (int coluna = 0; coluna < n; coluna++)
            {
                matriz[linha][coluna]=matriz[linha][coluna]+((-mL)*matriz[iteracao][coluna]);
            }
            vetor[linha]=vetor[linha]-(mL*vetor[iteracao]);
            
        }
        
        
    }
    calcularResultante(matriz,vetor,x);
}


int main(){
    
    double matriz[n][n];
    double vetor[n];
    double x[n];
    char estadoMetodo[2]={'o','o'};
    int escolha;
    zerarVetor(x);
    incluirVetor(vetor);
    incluirMatriz(matriz);
    do
    {
        printf("Escolha um metodo para ser resolvido: \n");
        if (estadoMetodo[0]=='o')
        {
            printf("1.Eliminacao de Gauss, Pivoteamento Total\n");
        }
         if (estadoMetodo[1]=='o')
        {
            printf("1.Eliminacao de Gauss, Pivoteamento Parcial\n");
        }
        //  if (estadoMetodo[2]=='o')
        // {
        //     printf("1.LU\n");
        // }
        //  if (estadoMetodo[3]=='o')
        // {
        //     printf("4.Gradiente\n");
        // }

        printf("5.Finalizar Testes\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            pivoteamentoParcial(matriz,vetor,x);
            imprimirMatriz(matriz,vetor);
            imprimirVetor(x);
            break;
        case 2:
             f=metodoGaussSeidel(x,n,c,NULL);
               for (int j = 0; j < 31; j++)
               {
                   if(j==0){
                   matriz[j][1]=(float)f;
                   }
                   else{
                    matriz[j][1]=x[j];
                   }
               }
            imprimirMatriz(matriz);
            estadoMetodo[1]='x';
            break;
        case 3:
             f=metodoSOR(x,n,c);
               for (int j = 0; j < 31; j++)
               {
                   if(j==0){
                   matriz[j][2]=(float)f;
                   }
                   else{
                    matriz[j][2]=x[j];
                   }
               }
            imprimirMatriz(matriz);
            estadoMetodo[2]='x';

            break;
        case 4: 
            f=metodoGradiente(x,n,c);
             for (int j = 0; j < 31; j++)
               {
                   if(j==0){
                   matriz[j][3]=(float)f;
                   }
                   else{
                    matriz[j][3]=x[j];
                   }
               }
            imprimirMatriz(matriz);
            estadoMetodo[3]='x';
            break;
        default:
            escolha=0;
            imprimirMatriz(matriz);

            break;
        }

    } while (escolha!=0);

     pivoteamentoTotal(matriz,vetor,x);
     imprimirMatriz(matriz,vetor);
     imprimirVetor(x);


    return 0;
}