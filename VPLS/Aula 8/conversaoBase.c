#include <stdio.h>
int casos(int num);
int transType(char num[],char tipo[],int tam);
char zerando(char v[]);
int limitador(char v[]);
int main(){
    int x=0;
    scanf("%d",&x);
    casos(&x);
    return 0;
}
int casos(int num){
    char tipo[3], numero[100000];
    int tam=0;
    zerador(numero);
    for (int i = 0; i < num; i++)
    {
        scanf("%s %s",numero,tipo);
        tam =limitador(numero);
        transType(numero, tipo, tam);
    }
}
int transType(char num[], char tipo[],int tam){
    int numero[tam],numeroInt=0,soma=0;
    if (tipo[0]=='d')
    {
        for (int i = 0; i < tam; i++)
        {
            switch (num[i])
            {
            case '0':
                numero[i]=0;
                break;
            case '1':
                numero[i]=1;
                break;
            case '2':
                numero[i]=2;
                break;
            case '3':
                numero[i]=3;
                break;
            case '4':
                numero[i]=4;
                break;
            case '5':
                numero[i]=5;
                break;
            case '6':
                numero[i]=6;
                break;
            case '7':
                numero[i]=7;
                break;
            case '8':
                numero[i]=8;
                break;
            case '9':
                numero[i]=9;
                break; 
            }
            
            
        }
        
    }else if (tipo[0]=='b')
    {
        for (int i = 0; i < tam; i++)
        {
            switch (num[i])
            {
            case '0':
                numero[i]=0;
                break;
            case '1':
                numero[i]=1;
                break;
            }
            
        }
        
    }
    
}
char zerando(char v[]){
for (int i = 0; i < 50 ; i++)
    {
        v[i]=0;
    }
}
int limitador(char v[]){
int tam=0;
    for (int i = 0; i < 100000 ; i++)
    {
        if (v[i]==0)
        {
            tam=i;
            break;
        }
    }
    return tam;
}
