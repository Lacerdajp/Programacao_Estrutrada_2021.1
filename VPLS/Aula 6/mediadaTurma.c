#include <stdio.h>
int main(){
    int n=0,soma=0,nalun=0;
    double media=0;
    printf("Digite o numero de alunos:\n");
    scanf("%d",&n);
    printf("Digite as notas dos alunos\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&nalun);
        soma=soma+nalun;
    }
    media=(double) soma/n;
    printf("A media e %.2lf",media);
    return 0;
}