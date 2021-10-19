#include <stdio.h>
int main()
{
    double number1;
    double number2;
    double number3;
    double media;
    printf("Digite o numero 1: \n");
    scanf("%lf", &number1);
    printf("Digite o numero 2: \n");
    scanf("%lf", &number2);
    printf("Digite o numero 3: \n");
    scanf("%lf", &number3);
    media = (number1 + number2 + number3) / 3;
    printf("sua media: %.3lf", media);

    return 0;
}