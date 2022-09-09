#include<stdio.h>
#include<math.h>
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
        // printf("Ordem das colunas: ");
        // for (int i = 0; i < N; i++)
        // {
        //     printf("%d ",x[i].posicao);
        //     if (i==N-1)
        //     {
        //         printf("\n");
        //     }
            
        // }
        
        
        for (int i = 0; i < N; i++)
        {
           for (int j = 0; j < N; j++)
           {
               if (j==(N-1))
               {
                   printf("%5.2lf = %5.2lf\n",matriz[i][j], vetor[i]);
               }
               else{
                   printf("%5.2lf ",matriz[i][j]);
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
void gerarMatrizIdentidade(double matriz[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i==j)
            {
                matriz[i][j]=1;
            }else
            {
                matriz[i][j]=0;
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
void passaVetor(Vector x[],double y[]){
    for (int i = 0; i < N; i++)
    {
        y[i]=x[i].valor;
    }
    
}

//Calculo de Resolução de Sistemas
void calcularTriangularSuperior(double matriz[N][N],double vetor[],Vector x[]){
    double soma=0;
    for (int linha = N-1; linha >=0; linha--)
    {   
        soma=0;
        for (int coluna = N-1; coluna >=0; coluna--)
        {
            if (linha==coluna)
            {
                x[coluna].valor=(vetor[linha]-soma)/matriz[linha][coluna];
                // printf("(%d) %.2lf = %.2lf - %.2lf/ %.2lf(linha %d coluna %d)\n ",x[coluna].posicao,x[coluna].valor,  vetor[linha], soma, matriz[linha][coluna],linha, coluna);
                break;
            }
            else{
                soma=soma+(matriz[linha][coluna]*x[coluna].valor);
                // printf(" %.2lf + %.2lf* %.2lf(linha %d coluna %d  ele e x%d)\n ",soma, matriz[linha][coluna],x[coluna].valor,linha, coluna,x[coluna].posicao);
            }
        }
    }  
}
void calcularTriangularInferior(double matriz[N][N],double vetor[],Vector x[]){
     double soma=0;
    for (int linha = 0; linha < N; linha++)
    {   
        soma=0;
        for (int coluna = 0; coluna < N; coluna++)
        {
            if (linha==coluna)
            {
                x[coluna].valor=(vetor[linha]-soma)/matriz[linha][coluna];
                // printf("(%d) %.2lf = %.2lf - %.2lf/ %.2lf(linha %d coluna %d)\n ",x[coluna].posicao,x[coluna].valor,  vetor[linha], soma, matriz[linha][coluna],linha, coluna);
                break;
            }
            else{
                soma=soma+(matriz[linha][coluna]*x[coluna].valor);
                // printf(" %.2lf + %.2lf* %.2lf(linha %d coluna %d  ele e x%d)\n ",soma, matriz[linha][coluna],x[coluna].valor,linha, coluna,x[coluna].posicao);
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
            if (fabsf(matriz[linha][iteracao])>fabsf(matriz[linhaMaior][iteracao]))
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
    calcularTriangularSuperior(matriz,vetor,x);
}
//eliminação por pivoteamento total
double definirPivoTotal(double matriz[N][N],double vetor[],int iteracao,Vector x[]){
    double pivo;
    double aux;
    int auxInt;
    int c=0;
    int maior=iteracao;
    double maiorValor;
    // int maiorLinha,maiorCol;
    // maiorLinha=maiorCol=iteracao;
    pivo=maiorValor=matriz[iteracao][iteracao];
       for (int coluna = iteracao; coluna < N; coluna++)
        {
            if (fabsf(matriz[iteracao][coluna])>=fabsf(maiorValor))
            {
                maiorValor=matriz[iteracao][coluna];
                c=1;
                maior=coluna;
            }
        } 
        for (int linha = iteracao; linha < N; linha++)
        {
            if (fabsf(matriz[linha][iteracao])>=fabsf(maiorValor))
            {
                maiorValor=matriz[linha][iteracao];
                c=2;
                maior=linha;
            }
        }
         
        if (c==1)
        {
            //  printf("\nFOI TROCADO Colunas %d e %d",iteracao, maiorColuna);
            for (int linha = 0; linha < N; linha++)
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
        for (int coluna = 0; coluna < N; coluna++)
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
    //   printf("\nNumero da Iteracao %d: Matriz antes das trocas de Linhas\n ",iteracao);
    //       imprimirMatriz(matriz,vetor); 
        
        pivo=definirPivoTotal(matriz,vetor,iteracao,x);
        //  printf("\nNumero da Iteracao %d: Matriz depos das trocas de Linhas\n ",iteracao);
        //    imprimirMatriz(matriz,vetor);
        //    printf("\n------------------------------------------------------------------------------------------------------------------\n");
        
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
    calcularTriangularSuperior(matriz,vetor,x);
}
//decomposição LU
double definirPivoTotalLU(double matriz[N][N],double vetor[],int iteracao){
    double pivo;
    double aux;
    int c=0;
    int maior=iteracao;
    double maiorValor;
    // int maiorLinha,maiorCol;
    // maiorLinha=maiorCol=iteracao;
    pivo=maiorValor=matriz[iteracao][iteracao];
       for (int coluna = iteracao; coluna < N; coluna++)
        {
            if (fabsf(matriz[iteracao][coluna])>=fabsf(maiorValor))
            {
                maiorValor=matriz[iteracao][coluna];
                c=1;
                maior=coluna;
            }
        } 
        for (int linha = iteracao; linha < N; linha++)
        {
            if (fabsf(matriz[linha][iteracao])>=fabsf(maiorValor))
            {
                maiorValor=matriz[linha][iteracao];
                c=2;
                maior=linha;
            }
        }
         
        if (c==1)
        {
            //  printf("\nFOI TROCADO Colunas %d e %d",iteracao, maiorColuna);
            for (int linha = 0; linha < N; linha++)
            {
                aux=matriz[linha][maior];
                    matriz[linha][maior]=matriz[linha][iteracao];
                    matriz[linha][iteracao]=aux;
            }
            
        }
        
        if (c==2)
        {
        // printf("\nFOI TROCADO LINHAS %d e %d",iteracao, maiorLinha);
        for (int coluna = 0; coluna < N; coluna++)
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
void decomposicaoLU(double matriz[N][N], double vetor[]){
   double pivo;
   double m[N][N];
   for (int iteracao = 0; iteracao < N; iteracao++)
    {   
    //   printf("\nNumero da Iteracao %d: Matriz antes das trocas de Linhas\n ",iteracao);
    //       imprimirMatriz(matriz,vetor); 
        
       pivo=definirPivoTotalLU(matriz,vetor,iteracao);
        //  printf("\nNumero da Iteracao %d: Matriz depos das trocas de Linhas\n ",iteracao);
        //   imprimirMatriz(matriz,vetor);
        //   printf("\n------------------------------------------------------------------------------------------------------------------\n");
        
        for (int linha = iteracao+1; linha < N; linha++)
        {
            m[linha][iteracao]=-matriz[linha][iteracao]/pivo;
            matriz[linha][iteracao]=-m[linha][iteracao];
            for (int coluna = iteracao+1; coluna < N; coluna++)
            {
                matriz[linha][coluna]=matriz[linha][coluna]+(m[linha][iteracao]*matriz[iteracao][coluna]);
            }
            
        }
    }
}
void separarLU(double matriz[N][N], double vetor[],Vector x[]){

   double L[N][N];
    double U[N][N];
    double m;
    for (int  linha = 0; linha < N; linha++)
    {
        for (int coluna= 0; coluna < N; coluna++)
        {
            
            if(coluna==linha){
                L[linha][coluna]=1;
                U[linha][coluna]=matriz[linha][coluna];
            }
            else if (linha>coluna)
            {
                m= matriz[linha][coluna];
                L[linha][coluna]=m;
                U[linha][coluna]=0;
            }
            else{
                U[linha][coluna]=matriz[linha][coluna];
                L[linha][coluna]=0;
            }
            
        }
        
    }
    printf("matriz L: \n");
    calcularTriangularInferior(L,vetor,x);
    imprimirMatriz(L,vetor);
    imprimirVector(x);
    printf("\n");
    printf("matriz U: \n");
    passaVetor(x,vetor);
    calcularTriangularSuperior(U,vetor,x);
    imprimirMatriz(U,vetor);
    imprimirVector(x);
    printf("\n");

}
void decomposicaoCholesky(double matriz[N][N],double vetor[],Vector x[]){
    double ml;
    int z=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(matriz[i][j]!=matriz[j][i]||(i==j && matriz[i][j]==0)){
                printf("Nao ha solucao");
                z++;
                break;
            }
            
        }
        if(z!=0) break;
        
    }
    if (z==0)
    {
        for (int iteracao = 0; iteracao < N; iteracao++)
    {
        matriz[iteracao][iteracao]= sqrt(matriz[iteracao][iteracao]);
       for (int linha = iteracao+1; linha < N; linha++)
        {
            ml=matriz[linha][iteracao]/matriz[iteracao][iteracao];
            for (int coluna = iteracao+1; coluna < N; coluna++)
            {
                matriz[linha][coluna]=matriz[linha][coluna]+((-ml)*matriz[iteracao][coluna]);
            }
            vetor[linha]=vetor[linha]-(ml*vetor[iteracao]);
            
        }
        
    }
    calcularTriangularSuperior(matriz,vetor,x);
    imprimirMatriz(matriz,vetor);
    imprimirVector(x);
    printf("A e simetrica definida positiva");
    
    }
    
    
   
    
     
    
}
void calcularInversa(double matriz[N][N], double  vetor[]){
    double identidade[N][N];
    double pivo;
    double m;
    double aux;
    gerarMatrizIdentidade(identidade);
    for(int coluna = 0; coluna < N; coluna++){
    pivo = matriz[coluna][coluna];
    	for(int k = 0; k < N; k++){
		matriz[coluna][k] = (matriz[coluna][k])/(pivo); //L1 -> L1/pivo , L2 -> L2/pivo, L3 -> L3/pivo
		identidade[coluna][k] = (identidade[coluna][k])/(pivo); //Ex: 1 0 0 / pivo  , 0 1 0 / pivo,   0 0 1/ pivo
        }
    
	for(int linha = 0; linha < N; linha++){
		if(linha != coluna){
			m = matriz[linha][coluna];
           			for(int k = 0; k < N; k++){
			matriz[linha][k] = (matriz[linha][k]) - (m*matriz[coluna][k]); //Ex: L2 -> L2 - ( 1"m" - L1) 
			identidade[linha][k] = (identidade[linha][k]) - (m*identidade[coluna][k]);  
    			}
    		}
    	}  
}
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            aux=matriz[i][j];
            matriz[i][j]=identidade[i][j];
            identidade[i][j]=aux;
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
    incluirMatriz(matriz);
        printf("Escolha um metodo para ser resolvido: \n");
            printf("1.Eliminacao de Gauss, Pivoteamento Total(Questao 1.1)\n");
            printf("2.Eliminacao de Gauss, Pivoteamento Parcial(Questao 1.2)\n");
            printf("3. LU sem a solucao(Questao 2) \n");
            printf("4.LU com resolucao (Questao 3.1) \n");
            printf("5. Matriz Inversa De LU(Questao 3.2)\n");
            printf("6. Decomposicao cholensky(Questao 4)\n");
        
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
        case 3:
        decomposicaoLU(matriz,vetor);
         imprimirMatriz(matriz,vetor);
            break;
        case 4:
            decomposicaoLU(matriz, vetor);
            separarLU(matriz,vetor,x);
            break;
        case 5:
            decomposicaoLU(matriz, vetor);
            calcularInversa(matriz,vetor);
            imprimirMatriz(matriz,vetor);
            break;
        case 6:
            decomposicaoCholesky(matriz,vetor,x);
            break;
        default:
            escolha=0;
            break;
        }
    return 0;
}