#include <stdio.h>

int main(){

    int linhas, colunas; 
    printf("Digite o numero de linhas e colunas, respectivamente:");
    scanf("%d %d", &linhas, &colunas);
    int matriz[linhas][colunas];
    
    printf("Digite os valores da matriz:\n");

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("matriz[%d] [%d]:", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(int i = 0; i < linhas; i++){
    printf("\n|");
        for(int j = 0; j < colunas; j++){
            if (j==colunas-1)printf("%d", matriz[i][j]);
            else
            printf("%d ", matriz[i][j]);
        }
        printf("|");
    }
    
    




    return 0;
}