#include<stdio.h>
void inserirValores(int valores[]){
    printf("Digite 10 valores : ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&valores[i]);
    }
}
void ordenacao(int v[]){
    int temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (v[j]>v[j+1])
            {
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
        
    }
    
}
void imprimir(int v[]){
    printf("Os valores sao: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",v[i]);
    }
    
}
int main(){
    int valores[10];
    inserirValores(valores);
    ordenacao(valores);
    imprimir(valores);
    return 0;
    }