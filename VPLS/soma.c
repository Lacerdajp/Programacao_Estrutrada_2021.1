#include <stdio.h>

int main()
{
    int numero1 = 0;
    int numero2 = 0;
    int soma = 0;
    printf("Digite o Valor 1: \n");
    scanf("%d", &numero1);
    printf("Digite o Valor 2: \n");
    scanf("%d", &numero2);
    soma = numero1 + numero2;
    printf("X = %d", soma);
    return 0;
};