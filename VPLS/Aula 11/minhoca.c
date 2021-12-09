#include<stdlib.h>
char caminho(int d );
char buscar(char matriz[][], int d);
int main(){
    int d=0;
    scanf("%d",&d);
    caminho(d);
    return 0;
}
char caminho(int d){
    char matriz[d][d]={0};
    for (int i = 0; i < d; i++)//linhas
    {
        for (int j = 0; j < d; j++)//colunas
        {
            scanf("%c",matriz[i][j]);
        }
    }
    buscar(matriz,d);
}
char buscar(char matriz[][], int d){
    int count=0,linhas=0,colunas=0,m1=0;
}