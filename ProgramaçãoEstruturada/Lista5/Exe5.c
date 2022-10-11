#include <stdio.h>
int main()
{
    double f = 0, c = 0;
    printf("Digite a temperatura em Fahrenheit:");
    scanf("%lf", &f);
    c = (f - 32) * 5 / 9;
    printf("A temperatura em celsius e : %.2lf", c);

    return 0;
}