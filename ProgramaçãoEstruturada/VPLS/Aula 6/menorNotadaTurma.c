#include <stdio.h>
int main()
{
    int n = 0, menornota = 10, notaAluno = 0;
    printf("Digite o numero de alunos:\n");
    scanf("%d", &n);
    printf("Digite as notas dos alunos\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &notaAluno);
        if (notaAluno >= 0 && notaAluno <= 10)
        {

            if (menornota > notaAluno)
            {
                menornota = notaAluno;
            }
        }
    }
    printf("a menor nota e %d", menornota);
    return 0;
}