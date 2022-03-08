#include<stdio.h>
#include"../../../LibsJPLS/cadeiaDeCarcteres.h"
#define TAM 1000
int main(){
    char nome[]={0}, letra =0;
    int num=0;
    fgets(nome, TAM ,stdin);
    scanf("%c", &letra);
    num=ultima_ocorrencia_letra(&nome, letra);
    printf("%d",num );
    return 0;
}