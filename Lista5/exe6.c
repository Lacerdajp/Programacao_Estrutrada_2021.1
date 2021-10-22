#include <stdio.h>
int main()
{
    double p = 0, a = 0;
    const double pi = 3.1416;
    printf("Digite o perimetro do circulo:");
    scanf("%lf", &p);
    a = pi * (p / (2 * pi)) * (p / (2 * pi));
    printf("a area do circulo e : %.2lf", a);

    return 0;
}