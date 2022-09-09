#include <stdio.h>
#include <math.h>
#define N 100
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
    
    
}
int main()
{
    int linha;
    int coluna;
    //Testes
    // double v1[3]={1, 0, 3};
    // double v2[3]={-1,4,2};
    double matrizTeste[N][N];
    //PRAVALER
    printf("Qual o Tamanho da matriz que deseja implementatar(linhas e colunas respectivamente):\n");
    scanf("%d %d", &linha, &coluna);
    gerarMatriz(matrizTeste, linha, coluna);
    calcularInversa(matrizTeste,linha,coluna);
    imprimirMatriz(matrizTeste,linha,coluna);
    return 0;
}