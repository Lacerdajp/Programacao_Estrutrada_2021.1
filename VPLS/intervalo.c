#include <stdio.h>
int main()
{
    double valor = 0;
    printf("Digite um valor \n");
    scanf("%lf", &valor);
    if (valor >= 0 && valor <= 25)
    {
        printf("Intervalo [0,25]");
    }
    else if (valor > 25 && valor <= 50)
    {
        printf("intervalo (25,50]");
    }
    else if (valor > 50 && valor <= 75)
    {
        printf("intervalo (50,75]");
    }
    else if (valor > 75 && valor <= 100)
    {
        printf("intervalo (75,100]");
    }
    else
    {
        printf("Fora de intervalo");
    }

    return 0;
}