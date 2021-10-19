#include <stdio.h>
int main()
{
    int nota1 = 0;
    int nota2 = 0;
    int passagem = 0;
    printf("Digite um numero:\n");
    scanf("%d", &nota1);
    printf("Digite  um outro numero:\n");
    scanf("%d", &nota2);
    passagem = nota1;
    nota1 = nota2;
    nota2 = passagem;
    printf("Nota 1: %d\nNota 2: %d", nota1, nota2);
    return 0;
}
