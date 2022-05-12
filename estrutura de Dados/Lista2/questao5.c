#include<stdio.h>
#define TAM 1000
int ultima_ocorrencia_letra(char *s, char c){
    int num=-1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (c==s[i])
        {
            num=i;
        }
    }
    return num;
}
int main(){
    char nome[]={0}, letra =0;
    int num=0;
    fgets(nome, TAM ,stdin);
    scanf("%c", &letra);
    num=ultima_ocorrencia_letra(&nome, letra);
    printf("%d",num );
    return 0;
}