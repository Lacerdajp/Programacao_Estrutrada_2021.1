#include<stdio.h>   
int implementMatriz(int linhas, int colunas);
char saida(char matriz[100][100],int x,int y,char posicao);
int main(){
    int linhas=0, colunas=0;
    scanf("%d %d",&linhas,&colunas);    
    implementMatriz(linhas,colunas);
    return 0;
}
int implementMatriz(int linhas,int colunas){
    char matriz[100][100]={0};
    int x=0,y=0;

    for (int i = 0; i < linhas; i++)
    {
        for (int z = 0; z < colunas; z++)
        {
            scanf("%1s",&matriz[i][z]);
            if (matriz[i][z]=='I')
            {
                x=i;
                y=z;
            }   
        }
    }
    printf("%c",saida(matriz,x,y,'x'));
}
char saida(char matriz[100][100],int x,int y,char posicao){
    char result; 
    //pra cima
    // printf("pra Cima\n");
    if (posicao!='C')
    {
    if (matriz[x-1][y]=='F')
    {
         return 'S';
    }else if (matriz[x-1][y]=='B')
    {
        result= saida(matriz,x-1,y,'B');
        if (result=='S')
        {
             return 'S';
        }
    }}
    //pra baixo
    //   printf("pra Baixo\n");
    if (posicao!='B')
    {
     if (matriz[x+1][y]=='F')
    {
         return 'S';
    }else if (matriz[x+1][y]=='B')
    {
        result= saida(matriz,x+1,y,'C');
        if (result=='S')
        {
             return 'S';
        }
    }}
    //pra esquerda
    //   printf("pra Esquerda\n");
    if (posicao!='E')
    {
     if (matriz[x][y-1]=='F')
    {
         return 'S';
    }else if (matriz[x][y-1]=='B')
    {
        result= saida(matriz,x,y-1,'D');
        if (result=='S')
        {
            return 'S';
        }
    }
    }
    // printf("pra Direita\n");
    if (posicao!='D')
    {
     if (matriz[x][y+1]=='F')
    {
      return 'S';
    }else if (matriz[x][y+1]=='B')
    {
        result= saida(matriz,x,y+1,'E');
        if (result=='S')
        {
        return 'S';
        }
    }}
    
    return 'N';
}