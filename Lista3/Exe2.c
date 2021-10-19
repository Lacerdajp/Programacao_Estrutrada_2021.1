#include <stdio.h>

int main()
{
    double numero = 0.0;
    printf(" Digite um numero: \n");
    scanf("%lf", &numero);
    printf("Numero com uma casa decimal %.1lf \n", numero);
    printf("Numero com duas casa decimal %.2lf\n", numero);
    printf("Numero com tres casas decimais %.3lf\n", numero);

    return 0;
}