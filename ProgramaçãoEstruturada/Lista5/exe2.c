#include <stdio.h>
#include <math.h>
int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, delt = 0;
    printf("Digite o valor da variavel a:\n");
    scanf("%lf", &a);
    printf("Digite o valor da variavel b:\n");
    scanf("%lf", &b);
    printf("Digite o valor da variavel c:\n");
    scanf("%lf", &c);
    delt = (b * b) - (4 * a * c);
    x1 = (-b + sqrt(delt)) / (2 * a);
    x2 = (-b - sqrt(delt)) / (2 * a);
    printf("As raizes sao: %lf e %lf", x1, x2);

    return 0;
}