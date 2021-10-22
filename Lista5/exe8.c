#include <stdio.h>
int main()
{
    int c = 0, d = 0, m = 0;
    printf("Digite o comprimento em centimetros:");
    scanf("%d", &c);
    m = c / 100;
    c = c % 100;
    d = c / 10;
    c = c % 10;
    printf("a distancia e : %d metros, %d decimetros e %d centimetros", m, d, c);
    return 0;
}