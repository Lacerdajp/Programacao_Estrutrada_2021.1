#include <stdio.h>
#include <math.h>
#define N 50
//MAtriz
void zerarMatriz(double matriz[N][N], int linha, int coluna)
{
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {

            matriz[j][i] = 0.0;
        }
    }
}
void gerarMatriz(double matriz[N][N], int linha, int coluna)
{
    zerarMatriz(matriz, linha, coluna);
    for (int i = 0; i < linha; i++)
    {

        for (int j = 0; j < coluna; j++)
        {
            scanf("%lf", &matriz[i][j]);
        }
    }
}
void imprimirMatriz(double matriz[N][N], int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (j == (colunas - 1))
            {
                printf("%.2lf \n", matriz[i][j]);
            }
            else
            {
                printf("%.2lf ", matriz[i][j]);
            }
        }
    }
}
void gerarMatrizIdentidade(double matriz[N][N], int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = 0;
            }
        }
    }
}
void multiplicarMatrizes(double A[N][N],double B[N][N],double C[N][N],int linhaA,int colunaA,int linhaB,int colunaB){
    double aux=0;
    for(int i = 0; i < linhaA; i++) {
		for(int j = 0; j < colunaB; j++) {
			
			C[i][j] = 0;
			for(int x = 0; x < linhaB; x++) {
				aux +=  A[i][x] * B[x][j];
			}

			C[i][j] = aux;
			aux = 0;
		}
	}
    
}
void calcularInversa(double matriz[N][N], int linhas, int colunas)
{
    double identidade[N][N];
    double pivo;
    double m;
    double aux;
    gerarMatrizIdentidade(identidade, linhas, colunas);

    for (int coluna = 0; coluna < colunas; coluna++)
    {
        pivo = matriz[coluna][coluna];
        for (int k = 0; k < linhas; k++)
        {
            matriz[coluna][k] = (matriz[coluna][k]) / (pivo);         //L1 -> L1/pivo , L2 -> L2/pivo, L3 -> L3/pivo
            identidade[coluna][k] = (identidade[coluna][k]) / (pivo); //Ex: 1 0 0 / pivo  , 0 1 0 / pivo,   0 0 1/ pivo
        }

        for (int linha = 0; linha < linhas; linha++)
        {
            if (linha != coluna)
            {
                m = matriz[linha][coluna];
                for (int k = 0; k < colunas; k++)
                {
                    matriz[linha][k] = (matriz[linha][k]) - (m * matriz[coluna][k]); //Ex: L2 -> L2 - ( 1"m" - L1)
                    identidade[linha][k] = (identidade[linha][k]) - (m * identidade[coluna][k]);
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            aux = matriz[i][j];
            matriz[i][j] = identidade[i][j];
            identidade[i][j] = aux;
        }
    }
    free(identidade);
}
void calcularTransposta(double matriz[N][N],double mT[N][N],int linhas,int colunas){

    for (int  i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            mT[j][i]=matriz[i][j];
        }

    }


}
//vetor
void passaVetor(double a[], double b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
void somaVetores(double a[],double b[],int n){
    for (int i = 0; i < n; i++)
    {
        a[i]=a[i]+b[i];
    }

}
void zerarVetor(double a[],int n){
    for (int i = 0; i < n; i++)
    {
        a[i]=0;
    }

}
void imprimirVetor(double vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", vetor[i]);
    }
}
//Calculos
void projecao(double a[], double b[], int n)
{
    double somatorio1 = 0;
    double somatorio2 = 0;
    for (int i = 0; i < n; i++)
    {
        somatorio1 = a[i] * b[i] + somatorio1;
        somatorio2 = a[i] * a[i] + somatorio2;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = (somatorio1 / somatorio2) * a[i];
    }
}
double magnitude(double a[], int n)
{
    double somatorio = 0;
    for (int i = 0; i < n; i++)
    {
        somatorio = somatorio + (a[i] * a[i]);
    }
    return sqrt(somatorio);
}


//DeComposiçãoQR
void decomposicaoQR(double A[N][N],double Q[N][N],double R[N][N],int linhas,int colunas){
    double U[N][N];
    double somatorio[linhas];
    double a[linhas];
    double u[linhas];
    double m=0;
    double QT[N][N];
    zerarVetor(a,linhas);
    zerarMatriz(U,linhas,colunas);
    //AcharMatriz U
    for (int iteracoes = 0; iteracoes < colunas; iteracoes++)
    {
        zerarVetor(somatorio,linhas);
        for (int coluna = 0; coluna <iteracoes ; coluna++)
        {
            for (int linha = 0; linha < linhas; linha++)
            {
                u[linha]=U[linha][coluna];
                a[linha]=A[linha][iteracoes];
            }
            projecao(u,a,linhas);

            somaVetores(somatorio,u,linhas);

        }
        for (int linha = 0; linha < linhas; linha++)
        {
            U[linha][iteracoes]=A[linha][iteracoes]-somatorio[linha];

        }
        // printf(" %.2lf ",U[linha][iteracoes]);
        // printf("\n");
    }
    //achando o Q
    zerarVetor(u,linhas);
    for (int i = 0; i<colunas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            u[j]=U[j][i];
        }
        m=magnitude(u,linhas);
        for (int j = 0; j < linhas; j++)
        {
            Q[j][i]=u[j]/m;
        }
        
    }
    free(U);
    free(u);
    free(a);
    free(somatorio);
    //Achando o R
    zerarMatriz(QT,linhas,colunas);
    calcularTransposta(Q,QT,linhas,colunas);
    multiplicarMatrizes(QT,A,R,colunas,linhas,linhas,colunas);
    
}

//achar autovalores
void acharAutovalores(double matriz[N][N], double autovalores[], int linhas,int colunas, int interacoes){
    double Q[N][N];
    double R[N][N];
    zerarMatriz(Q,linhas,colunas);
    zerarMatriz(R,linhas,colunas);
    zerarVetor(autovalores,linhas); 
    // printf("i\n");
    //        imprimirMatriz(matriz,linhas,colunas);
    for (int i = 0; i < interacoes; i++)
    {
        if (i==0)
        {
            decomposicaoQR(matriz,Q,R,linhas,colunas); 
           
        }
        else
        {
            zerarMatriz(matriz,linhas,colunas);
            multiplicarMatrizes(R,Q,matriz,linhas,colunas,linhas,colunas);
            zerarMatriz(Q,linhas,colunas);
            zerarMatriz(R,linhas,colunas);
           decomposicaoQR(matriz,Q,R,linhas,colunas);
          
        }
        
    }
  
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (i==j)
            {
                autovalores[i]=matriz[i][j];
            
            }
        
    }
    
    
}}
//VerificaSiometrica
 int  isSimetrica(double matriz[N][N],int linha, int coluna ){
     double mT[N][N];
     zerarMatriz(mT,linha,coluna);
     if (linha!=coluna)
     {
         return 1;
     }else{
         calcularTransposta(matriz,mT,linha,coluna);
         for (int i = 0; i < linha; i++)
         {
            for (int j = 0; j < coluna; j++)
            {
                if (mT[i][j]!=matriz[i][j])
                {
                    return 1;
                }
                
            }
            
         }
     }
     return 0;
 }
int main()
{
    int linha;
    int coluna;    
    //Testes
    // double v1[3]={1, 0, 3};
    // double v2[3]={-1,4,2};
    double matrizTeste[N][N];
    double autoValores[N];
    double Q[N][N];
    double R[N][N];
    int iteracao=0;
    //PRAVALER
    printf("Qual o Tamanho da matriz que deseja implementatar(linhas e colunas respectivamente):\n");
    scanf("%d %d", &linha, &coluna);
    printf("Digite a matriz desejada: \n");
    gerarMatriz(matrizTeste, linha, coluna);
    if (isSimetrica(matrizTeste,linha,coluna)!=0)
    {
        printf("matriz nao simetrica, impossivel calcular metodo\n");
    }
    else{
         printf("Digite o nuumero de iteracao que deseja:\n");
         scanf("%d",&iteracao);
        printf("matriz original:\n");
        imprimirMatriz(matrizTeste,linha,coluna);

        acharAutovalores(matrizTeste,autoValores,linha,coluna,iteracao);
         printf("matriz da iteracao:\n");
        imprimirMatriz(matrizTeste,linha,coluna);
         printf("Autovalores:\n");
        imprimirVetor(autoValores,linha);
    }
    
  
    return 0;
}