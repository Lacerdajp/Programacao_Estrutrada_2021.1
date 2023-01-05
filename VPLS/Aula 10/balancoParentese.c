#include <stdio.h>
char verificacao(char v[], int tam);
char zerando (char v[]);
int limitador (char v[]);
int main(){
    int tam;
    char v[1000];
    zerando(v);
    scanf("%s",v);
    tam = limitador(v);
    verificacao(v,tam);


    return 0;
}
char verificacao(char v[],int tam){

    int esquerda=0,direita=0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i]==')')
        {
            esquerda++;
        }else if (v[i]=='(')
        {
            direita++;
        }
        if (esquerda>direita)
        {
            break;
        }
        
    }
    direita==esquerda ? printf("correct"):printf("incorrect");
}
char zerando (char v[]){
    for (int i = 0; i < 1000 ; i++)
    {
        v[i]=0;
    }
}
int limitador (char v[]){
    int tam=0;
    for (int i = 0; i < 1000 ; i++)
    {
        if (v[i]==0)
        {
            tam=i;
            break;
        }
    }
    return tam;
}