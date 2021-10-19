#include <stdio.h>

int main()
{
    double pi = 3.14159;
    double raio = 0;
    double area = 0;
    printf("Digite o Valor do Raio: \n");
    scanf("%lf", &raio);
    area = pi * (raio * raio);
    printf("A=%.4lf", area);
    return 0;
}
