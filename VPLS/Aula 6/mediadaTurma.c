#include <stdio.h>
int main()
{
    int n = 0, soma = 0, nalun = 0, var = 0;
    ;
    double media = 0;
    printf("Digite o numero de alunos:\n");
    scanf("%d", &n);
    printf("Digite as notas dos alunos\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nalun);
        if (nalun <= 10 && nalun >= 0)
        {
            soma = soma + nalun;
        }
        else
        {
            var--;
        }
    }

    media = (double)soma / (n + var);
    printf("A media e %.1lf", media);
    return 0;
}