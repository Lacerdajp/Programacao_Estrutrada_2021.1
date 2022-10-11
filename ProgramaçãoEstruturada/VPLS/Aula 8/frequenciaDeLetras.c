#include <stdio.h>
char casos(int *px);
char ignoreSensitive(char v2[], int tamanho1);
char frquencia(char v1[], int tamanho2);
char zerador(char v3[],int tam);
int main(){
    int x=0;
    printf("Digite o numero de casos: ");
    scanf("%d \n",&x);
    casos(&x);
    return 0;
}
char casos(int *px){
    char vetorEnt[200]; 
    for (int i = 0; i < *px; i++)
    {
        zerador(vetorEnt,200);
        fgets(vetorEnt,200,stdin);
        frquencia(vetorEnt,200);
    }
}
char frquencia(char v1[], int tamanho2){
    int somaMaior=0, soma=0,count=1;
    char letrasMaior[26];
    ignoreSensitive(v1,tamanho2);
    zerador(letrasMaior,26);
    for (int i = 0; i+'a' < 'z'; i++)
    {
        soma=0;
        for (int z = 0; z < tamanho2; z++)
        {
            if (v1[z]==i+'a'){
                soma=soma+1;
            }
        }
        if (soma>somaMaior)
        {
            somaMaior=soma;
            zerador(letrasMaior,26);
            letrasMaior[0]=i+'a';
            count=1;
            
        }else if (soma==somaMaior)
        {
            letrasMaior[0+count]=i+'a';
            count++; 
        }
    }
    printf("%s\n",letrasMaior);
}
char ignoreSensitive(char v2[],int tamanho1 ){

    for (int i = 0; i < tamanho1 ; i++)
    {
        if (v2[i]==0)
        {
            tamanho1=i;
            break;
        }
        if (v2[i]>='A'&& v2[i]<='Z')
        {
            v2[i]=(v2[i]-'A')+'a';
        }   
    }
}
char zerador(char v3[], int tam){
    for (int i = 0; i < tam; i++)
    {
        v3[i]=0;
    }
}

