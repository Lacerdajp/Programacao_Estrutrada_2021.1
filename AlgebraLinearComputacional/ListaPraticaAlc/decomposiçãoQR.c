#include<stdio.h>
#define N 3
void zerarmatriz(double matriz[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
           
            matriz[j][i]=0.0;
                
        }
        
    }
    
}
void imprimirMatriz(double matriz[N][N]){
        for (int i = 0; i < N; i++)
        {
           for (int j = 0; j < N; j++)
           {
               if (j==(N-1))
               {
                   printf("%.2lf \n",matriz[i][j]);
               }
               else{
                   printf("%.2lf ",matriz[i][j]);
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
void projecao(double u[],double a[]){

}
void decomposiçãoQRGS(double matriz[N][N]){
    double Q[N][N];
    double R[N][N];
    double U[N][N];
    zerarmatriz(Q);zerarmatriz(R);
    for (int coluna = 0; coluna < N; coluna++)
    {
        for (int linha = 0; linha < N; linha++)
        {
            if (coluna==0)
            {
                U[linha][coluna]=matriz[linha][coluna];
            }else{
                for (int i =0; i < coluna; i++)
                {
                       
                    
                }
                
            }
            
        }
        
    }
    
}
int main(){
    double matriz[N][N];
     zerarmatriz(matriz);
    for(int i=0; i<N;i++){

        for (int j = 0; j < N; j++)
        {
            scanf("%lf",&matriz[i][j]);
            
            
        }
    }
    imprimirMatriz(matriz);
    printf("\n");


    return 0;
}