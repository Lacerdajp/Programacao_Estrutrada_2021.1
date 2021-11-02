#include <stdio.h>
int main()
{
    double nota1 = 0, nota2 = 0;
    double media = 0;
    printf("Digite a nota 1: \n");
    scanf("%lf", &nota1);
    printf("Digite a nota 2: \n");
    scanf("%lf", &nota2);
    media = ((nota1 * 3.5) + (nota2 * 7.5)) / 11;
    printf("MEDIA = %.5lf", media);
    return 0;
}