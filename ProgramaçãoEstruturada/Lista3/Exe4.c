#include <stdio.h>
int main()
{
    int number = 0;
    double real = 0;
    char letra;
    printf("Digite um numero inteiro:\n");
    scanf("%d", &number);
    printf("Digite um Numero real:\n");
    scanf("%lf", &real);
    printf("Digite uma letra:\n ");
    scanf("%s", &letra);
    printf("Numero inteiro:%d\nNumero Real: %.2lf\nLetra:%c", number, real, letra);

    return 0;
}