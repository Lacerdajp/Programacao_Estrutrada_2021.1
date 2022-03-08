#include<stdio.h>
int incluirMatriz(int matriz[100][100],int m, int n);
int main(){
    int m=0,n=0,p=0;
    int matrizA[m][n];
    int matrizB[n][p];
    scanf("%d %d %d",&m,&n,&p);
    incluirMatriz(matrizA,m,n);
     printf("%d",matrizA[1][1]);
    incluirMatriz(matrizB,n,p);
    printf("%d",matrizA[1][1]);

}
int incluirMatriz(int matriz[100][100],int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d %d\n",i,j);
            scanf("%d",&matriz[i][j]);
            printf("%d\n",matriz[i][j]); 
            
        }
        
    }
    
    return 0;
}