#include <stdio.h>
int main(){
    int n=0,menorNota=10, notaluno=0,segundaMenorNota=10;
    printf("Digite o numero de alunos:\n");
    scanf("%d",&n);
    printf("Digite as as notas dos alunos\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&notaluno);
        if (notaluno<menorNota)
        {
            menorNota=notaluno;
        }else if (segundaMenorNota>notaluno>menorNota)
        {
            segundaMenorNota=notaluno;
        }
        
    }

    printf("A segunda menor nota e : %d",segundaMenorNota);

    return 0;
}